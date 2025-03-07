/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:58:23 by omartela          #+#    #+#             */
/*   Updated: 2025/03/07 12:58:25 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"
#include <algorithm>

int gen() 
{ 
    static int i = 0; 
    return ++i; 
}

int main()
{
    try {
		Span sp1 = Span(5);
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);
		std::cout << sp1.shortestSpan() << std::endl;
		std::cout << sp1.longestSpan() << std::endl;

        Span sp(5);

        sp.addNumber(10);
        sp.addNumber(20);
        sp.addNumber(30);
        sp.addNumber(5);
        sp.addNumber(15);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        Span sp_large(10000);
        std::srand(std::time(0));
        for (int i = 0; i < 10000; ++i) 
		{
            sp_large.addNumber(std::rand() % 100000);
        }

        std::cout << "Shortest span (large test): " << sp_large.shortestSpan() << std::endl;
        std::cout << "Longest span (large test): " << sp_large.longestSpan() << std::endl;
		std::vector<int> v1(20000); 

		std::generate(v1.begin(), v1.end(), gen);
		Span sp_verylarge(20000);
		
		sp_verylarge.addRange(v1.begin(), v1.end());
		std::cout << "Shortest span (large test): " << sp_verylarge.shortestSpan() << std::endl;
        std::cout << "Longest span (large test): " << sp_verylarge.longestSpan() << std::endl;
    }
    catch (const std::exception &e) 
	{
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
