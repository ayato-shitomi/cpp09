#include "BitcoinExchange.hpp"
#include <cstdlib>

void	putError(std::string msg) {
	std::cout << "\033[31m" << msg << "\033[0m" << std::endl;
	exit(1);
}

// function to convert a csv file to a map
std::map<std::string, double>	convertCsvToMap(std::string filePath) {
	std::ifstream	lowData(filePath.c_str());
	std::string 	line;
	std::map<std::string, double>	ret;

	// check if file exists
	if (lowData.fail()) {
		putError("Error: could not read " + filePath + ".");
	}
	// read file line by line
	while (std::getline(lowData, line)) {
		if (line == "date,exchange_rate")
			continue;
		// find the two commas
		size_t splitPoint1 = line.find(",");
		size_t splitPoint2 = line.find(",", splitPoint1 + 1);
		// check if file is valid
		if (line.size() < 12 || splitPoint1 == std::string::npos || splitPoint2 != std::string::npos) {
			putError("Error: invalid file format in " + filePath + ".");
		}
		// split line into key and value
		std::string key = line.substr(0, splitPoint1);
		std::string value = line.substr(splitPoint1 + 1, line.size() - splitPoint1 - 1);
		// convert value to double
		std::istringstream(value) >> ret[key];
	}
	// check if file is empty
	if (ret.size() == 0) {
		putError("Error: invalid file format in " + filePath + ".");
	}
	return ret;
}

int main(int ac, char **av) {
	// handle arguments
	if (ac != 2) {
		putError("Error: could not open file.\033[0m\n\nUsage\n\t./btc <input_file>\n");
	}
	// try to open file
	std::ifstream	input(av[1]);
	if (input.fail()) {
		putError("Error: could not read file '" + std::string(av[1]) + "'.");
	}
	// convert file to map
	std::map<std::string, double> data = convertCsvToMap("./data.csv");
	// create BitcoinExchange object
	BitcoinExchange be(data);
	// read input file line by line
	std::string line;
	// calculate rate for each line
	while (std::getline(input, line)) {
		be.rateCalculation(line);
	}
	return 0;
}