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

bool BitcoinExchange::isValidValue(std::string value, std::string line)
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

int BitcoinExchange::convertValue(std::string str) 
{ 
    if (str.back() == 'f')
        str.pop_back();
    std::stringstream ss(str); 
    int intValue; 
    ss >> intValue; 
    return intValue;
} 


void BitcoinExchange::processLines()
{
	
}

bool BitcoinExchange::isLeapYear(int year)
{
	// Leap year if divisible by 4, but not by 100 unless also divisible by 400
	 return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool BitcoinExchange::isValidDate(std::string date) 
{
	int day;
	int month;
	int year;

	if (date.empty())
		return false;
	std::stringstream streamLine(date);
	std::string d;
	std::string m;
	std::string y;

	getline(y, date, '-');
	getline(m, date, '-');
	getline(d, date);

	year = convertValue(y);
	month = convertValue(m);
	day = convertValue(d);
    // Check if the month is valid (1 to 12)
    if (month < 1 || month > 12) 
        return false;
    
    // Days in each month for non-leap years
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    // Adjust for leap year (February)
    if (isLeapYear(year)) 
        daysInMonth[1] = 29; // February has 29 days in a leap year
    
    // Check if the day is valid for the month
    if (day < 1 || day > daysInMonth[month - 1]) 
        return false;
    return true;
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

        if (std::regex_match(line, matches, pattern)) 
		{
            std::string date = matches[1];
            std::string number = matches[2];
			if (isValidDate(date) && isValidValue(number, line))
			{

			}
		}
		else
		{
			std::cout << "Error: bad input" << std::endl;
		}
	}
}