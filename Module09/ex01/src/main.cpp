/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:18:14 by omartela          #+#    #+#             */
/*   Updated: 2025/03/19 10:18:16 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "../inc/RPN.hpp"
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./RPN numbers and operators inside string" << std::endl;
    }
    else
    {
        RPN rpn;
        rpn = RPN();
        char *str = argv[1];
        std::stringstream ss(str);
        std::string token;
        while (getline(ss, token, ' '))
        {
            if (!rpn.isValidValue(token) && !rpn.isOperator(token))
            {
                std::cerr << "Error" << std::endl;
                return (-1);
            }
            if (rpn.isOperator(token))
                rpn.incNoperators();
            if (rpn.isValidValue(token))
                rpn.incNoperands();
        }
        // The number of operands will always be one more than the number of operators
        if (rpn.getNoperands() - rpn.getNoperators() < 1)
        {
            std::cerr << "Error: incorrect amount of operands or operators" << std::endl;
            return (-1);
        }
        try
        {
            char *str = argv[1];
            std::stringstream ss(str);
            std::string token;
            while (getline(ss, token, ' '))
            {
                if (rpn.isValidValue(token))
                    rpn.add(token);
                else if (rpn.isOperator(token))
                    rpn.calculate(token);
                else
                    throw std::runtime_error("Error");
            }
            std::cout << rpn.getResult() << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}