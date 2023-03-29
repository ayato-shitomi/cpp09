#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <iostream>
# include <sstream>

class BitcoinExchange 
{
	private:
		BitcoinExchange(BitcoinExchange const &);
		typedef				std::map<std::string, double>	BEdata;
		BEdata				_data;
		BitcoinExchange		&operator=(BitcoinExchange const &);
		bool				_validateLine(std::string line);
		bool				_validateKey(std::string year, std::string month, std::string day);
		bool				_validateValue(std::string value);
		void				_putErrorForRateCalculation(std::string msg);

	public:
		BitcoinExchange(BEdata data);
		~BitcoinExchange();
		void	rateCalculation(std::string line);
};

#endif
