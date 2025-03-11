/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:45:54 by omartela          #+#    #+#             */
/*   Updated: 2025/03/11 11:45:55 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"
#include <fstream>
#include <regex>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string filename) 
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
	{

	}
}

bool isValidValue(std::string value, std::string line)
{
	if (value.back() == 'f')
        value.pop_back();
    std::stringstream ss(value); 
    int intValue; 
    ss >> intValue;
	if (!ss.eof())
	{
		std::cout << "Error: bad input " << line << std::endl;
		return (false);
	}
	if (ss.fail() && ss.eof())
	{
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	if (intValue < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (intValue > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}

}

int convertValue(std::string str) 
{ 
    if (str.back() == 'f')
        str.pop_back();
    std::stringstream ss(str); 
    int intValue; 
    ss >> intValue; 
    return intValue;
} 

bool isValidDate(std::string date)
{
	std::regex pattern(R"((\d{4}-\d{2}-\d{2}))");
    std::smatch matches;
}

void BitcoinExchange::processLines()
{
	
}

void BitcoinExchange::readCsv()
{
	std::ifstream file("data.csv");
	
	if (!file.is_open())
	{
		throw std::runtime_error("File could not be opened");
	}
	std::string line;
	getline(file, line);
	if (line != "date,exchange_rate")
	{
		throw std::runtime_error("Invalid file data.csv");
	}
	while (getline(file, line))
	{
		std::stringstream streamLine(line);
		std::string date;
		std::string value;
		float rate;
		getline(streamLine, date, ',');
		getline(streamLine, value); 
		rate = convertValue(value);
		_data.insert({date, rate});
	}
}

void BitcoinExchange::readfile()
{
	std::ifstream file(_filename);
	
	if (!file.is_open())
	{
		throw std::runtime_error("File could not be opened");
	}
	std::string line;
	getline(file, line);
	if (line != "date | value")
	{
		throw std::runtime_error("Invalid file input file");
	}
	while (getline(file, line))
	{
		std::string line;
    	std::regex pattern(R"((\d{4}-\d{2}-\d{2})\s*\|\s*(-?\d+(\.\d+)?)))");
    	std::smatch matches;

    while (std::getline(file, line)) 
	{
        if (std::regex_match(line, matches, pattern)) 
		{
            std::string date = matches[1];  // First capture group: date
            std::string number = matches[2]; // Second capture group: number
			if (isValidDate(date) && isValidValue(number, line))
			{

			}
		}
		else
		{
			/// error bad input
		}
	}
}