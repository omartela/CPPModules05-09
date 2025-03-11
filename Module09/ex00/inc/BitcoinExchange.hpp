/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:45:33 by omartela          #+#    #+#             */
/*   Updated: 2025/03/11 11:45:34 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <map>
class BitcoinExchange
{
	private:
		std::string _filename;
		std::map<std::string, float>	_data;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string filename);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange& operator=(const BitcoinExchange &src);
		void readfile();
		void processLines();
		bool isValidValue(std::string value, std::string line);
		bool isValidDate(std::string date);
		int	convertValue(std::string str);
		void	readCsv();	
};


