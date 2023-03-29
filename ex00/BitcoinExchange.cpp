#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(BEdata	data) {
	_data = data;
}

BitcoinExchange::~BitcoinExchange() {
}

// function to validate the given line
bool	BitcoinExchange::_validateLine(std::string	line) {
	size_t	max = 13;

	if (line.size() < max)
		return false;
	for (size_t n = 0; n < max; n++) {
		if (!std::isdigit(line[n]) && (n < 4 || n == 5 || n == 6 || n == 8 || n == 9))
			return false;
		if (line[n] != '-' && (n == 4 || n == 7))
			return false;
		if (line[n] != ' ' && (n == 10 || n == 12))
			return false;
		if (line[n] != '|' && n == 11)
			return false;
	}
	return true;
}

// function to validate the given date. return true if valid.
bool	BitcoinExchange::_validateKey(std::string y, std::string m, std::string d) {
	// convert string to int
	int year;
	int month;
	int day;
	std::istringstream(y) >> year;
	std::istringstream(m) >> month;
	std::istringstream(d) >> day;

	// check if the date is valid: 2/29
	if (month == 2 && day > 29)
		return false;
	if (month == 2 && day == 29 && year % 4 != 0)
		return false;
	// check if the date is valid: 4/6/9/11 with 30 days
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	// check if the date is valid
	if (year < 2009 || 2022 < year || month < 1 || 12 < month || day < 1 || 31 < day)
		return false;
	return true;
}

// function to validate the given value as a bitcoin prise. return true if valid.
bool	BitcoinExchange::_validateValue(std::string value) {
	int dot = 0;

	// check if the value is a number or a dot
	for (size_t i = 0; i < value.size(); i++) {
		// check if the value is a number or a dot
		if (!std::isdigit(value[i]) && value[i] != '.')
			return false;
		// check if there is more than one dot
		if (value[i] == '.')
			dot++;
		// return false if there is more than one dot
		if (dot > 1)
			return false;
	}
	return true;
}

void	BitcoinExchange::_putErrorForRateCalculation(std::string msg) {
	std::cout << "\033[31m" << "[*] ERROR " << msg << "\033[0m" << std::endl;
}

void	BitcoinExchange::rateCalculation(std::string line) {
	// check if the line is the header
	if (line == "date | value")
		return;
	// check if the line is valid
	if (!_validateLine(line)) {
		_putErrorForRateCalculation("Invalid line: " + line);
		return;
	}
	std::string	year = line.substr(0, 4);
	std::string	month = line.substr(5, 2);
	std::string	day = line.substr(8, 2);
	// check if the date is valid
	if (!(_validateKey(year, month, day))) {
		_putErrorForRateCalculation("Invalid date: " + line);
		return;
	}
	std::string data = line.substr(0, 10);
	std::string value = line.substr(13, line.size() - 13);
	// check if the value is empty
	if (value.empty()) {
		_putErrorForRateCalculation("Invalid value: null");
		return;
	}
	// check if the value is valid
	if (!(_validateValue(value))) {
		_putErrorForRateCalculation("Invalid value: " + value);
		return;
	}
	double val;
	std::istringstream(value) >> val;
	// check if the value is too large
	if (val > 1000) {
		_putErrorForRateCalculation("Too large: " + value);
		return;
	}
	BEdata::iterator rating = _data.lower_bound(data);
	if (rating->first != data) {
		if (rating == _data.begin())
			_putErrorForRateCalculation("Out of range: " + data);
		rating--;
	}
	std::cout << data << " => " << value << " \t=\t" << rating->second * val << std::endl;
}