/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:46:18 by omartela          #+#    #+#             */
/*   Updated: 2025/03/20 15:25:36 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"
#include <sstream>
#include <climits> // For INT_MAX and INT_MIN

RPN::RPN() 
{
	Noperands = 0;
	Noperators = 0;
}

RPN::~RPN() {}

RPN::RPN(const RPN &src)
{
	st = src.st;
}

RPN &RPN::operator=(const RPN &src)
{
    if (this != &src)
		st = src.st;
    return *this;
}

bool RPN::isValidValue(std::string value)
{
    std::stringstream ss(value); 
    int IntValue; 
    ss >> IntValue;
	if (!ss.eof())
		return (false);
	if (ss.fail() && ss.eof())
		return (false);
	return true;
}

bool RPN::isOperator(std::string str)
{
	if (str.length() != 1)
		return false;
	if (str != "*" && str != "-" && str != "+" && str != "/")
		return false;
	return true;
}

int RPN::convertValue(std::string str) 
{ 
    std::stringstream ss(str); 
    int IntValue; 
    ss >> IntValue; 
    return IntValue;
}

void RPN::add(std::string str)
{
	int number = convertValue(str);
	st.push(number);
}

void RPN::incNoperands()
{
	Noperands++;
}

void RPN::incNoperators()
{
	Noperators++;
}

double RPN::getNoperands()
{
	return Noperands;
}

double RPN::getNoperators()
{
	return Noperators;
}

int RPN::getResult()
{
    if (st.empty())
        throw std::runtime_error("Error: No result available");
    return st.top();
}

void RPN::calculate(std::string str)
{
    if (st.size() < 2)
        throw std::runtime_error("Error: Not enough operands for operation");

    int number2 = st.top();
    st.pop();
    int number1 = st.top();
    st.pop();

    double operationResult = 0; // Use double to handle intermediate results

    if (str == "+")
    {
        operationResult = static_cast<double>(number1) + static_cast<double>(number2);
    }
    else if (str == "-")
    {
        operationResult = static_cast<double>(number1) - static_cast<double>(number2);
    }
    else if (str == "*")
    {
        operationResult = static_cast<double>(number1) * static_cast<double>(number2);
    }
    else if (str == "/")
    {
        if (number2 == 0)
            throw std::runtime_error("Error: Division by zero is not possible");
        operationResult = static_cast<double>(number1) / static_cast<double>(number2);
    }
    else
    {
        throw std::runtime_error("Error: Invalid operator");
    }

    // Check if the result is within the range of an int
    if (operationResult > INT_MAX || operationResult < INT_MIN)
        throw std::overflow_error("Error: Arithmetic overflow");

    // Push the result back onto the stack as an int
    st.push(static_cast<int>(operationResult));
}
