/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:46:51 by omartela          #+#    #+#             */
/*   Updated: 2025/03/11 11:46:53 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/BitcoinExchange.hpp"
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: program file.txt" << std::endl;
		return -1;
	}
	try
	{
		BitcoinExchange btc;
		btc =  BitcoinExchange();
		btc.readfile(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}