/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:46:18 by omartela          #+#    #+#             */
/*   Updated: 2025/03/19 09:46:19 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"
#include <sstream>

RPN::RPN() 
{
	result = 0;
}

RPN::~RPN() {}

RPN::RPN(const RPN &src)
{
	st = src.st;
	result = src.result;
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

RPN &RPN::operator=(const RPN &src)
{
    if (this != &src)
    {
		st = src.st;
		result = src.result;
    }
    return *this;
}

void RPN::add(std::string str)
{
	float number = convertValue(str);
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
	return result;
}

void RPN::calculate(std::string str)
{
	if (st.empty())
		throw std::runtime_error("Error:");
	int number1 = st.top();
	st.pop();
	int number2 = 0;
	if (st.size() >= 2)
	{
		number2 = st.top();
		st.pop();
	}
	if (str == "-")
		result += (number1 - number2);
	else if (str == "+")
		result += (number1 + number2);
	else if (str == "/")
	{
		if (number2 == 0)
			throw std::runtime_error("Error: Division by zero is not possible");
		result += (number1 / number2);
	}
	else if (str == "*")
		result += (number1 * number2);
	else
		throw std::runtime_error("Error: value is not operand or operator");
}
