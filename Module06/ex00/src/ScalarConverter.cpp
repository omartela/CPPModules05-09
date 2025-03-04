/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:25:48 by omartela          #+#    #+#             */
/*   Updated: 2025/03/02 10:25:49 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"


template <class T> T stringToType(std::string str)
{
    if (str.back() == 'f')
        str.pop_back();
    std::istringstream iss(str);
    T result;
    iss >> result;
    if (!(!iss.fail() && iss.eof()))
    {
        throw std::runtime_error("impossible");
    }
    return result;
}

bool isInteger(std::string str) 
{
    if (str.back() == 'f')
        str.pop_back();
    std::stringstream ss(str);
    int intValue; 
    ss >> intValue; 
    return ss.eof() && !ss.fail(); // Check if we reached the end and no conversion error occurred 
}

bool isDouble(std::string str) 
{
    if (str.back() == 'f')
        str.pop_back();
    std::stringstream ss(str); 
    double doubleValue; 
    ss >> doubleValue; 
    return ss.eof() && !ss.fail(); // Check if we reached the end and no conversion error occurred 
}
 
bool isFloat(std::string str) 
{ 
    if (str.back() == 'f')
        str.pop_back();
    std::stringstream ss(str); 
    float floatValue; 
    ss >> floatValue; 
    return ss.eof() && !ss.fail(); // Check if we reached the end and no conversion error occurred 
} 
 
bool isCharacter(const std::string str) 
{ 
    return str.length() == 1 && std::isalpha(str[0]); // Check if it's a single alphabetic character 
} 

bool hasMultipleDots(const std::string &str)
{
    size_t dotCount = 0;
    for (char c : str)
    {
        if (c == '.')
        {
            dotCount++;
            if (dotCount > 1)
                return true;
        }
    }
    return false;
}

int getPrecision(const std::string str)
{
    size_t dotPos = str.find('.');
    if (dotPos == std::string::npos)
        return 1;

    size_t endPos = str.find('f', dotPos);
    if (endPos == std::string::npos || endPos != str.length() - 1)
        endPos = str.length();

    return endPos - dotPos - 1;
}

static void handleSpecialCases(const std::string &str) 
{
    if (str == "-inff" || str == "+inff") 
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << std::endl;
        if (str == "-inff") 
            std::cout << "double: -inf" << std::endl;
        else 
            std::cout << "double: +inf" << std::endl;
    } 
    else if (str == "nanf" || str == "nan") 
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}

void tryConvert(const std::string &str)
{
    int precision = getPrecision(str);
    try
    {
        if (str.length() == 1 && isalpha(str[0]))
        {
            std::cout << "char: '" << str[0] << "'" << std::endl;
        }
        else
        {
            int value = stringToType<int>(str);
            std::cout << "char: ";
            if (value >= CHAR_MIN && value <= CHAR_MAX && isprint(static_cast<int>(value))) 
            {
                std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
            } 
            else 
            {
                std::cout << "Non displayable" << std::endl;
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cout << "char: impossible" << std::endl;
    }
    try
    {
        int value = stringToType<int>(str);
        std::cout << "int: " << std::fixed << std::setprecision(precision) << value << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "int: impossible" << std::endl;
    }
    try
    {
        float value = stringToType<float>(str);
        std::cout << "float: " << std::fixed << std::setprecision(precision) << value << "f" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "float: impossible" << std::endl;
    }
    try
    {
        double value = stringToType<double>(str);
        std::cout << "double: " << std::fixed << std::setprecision(precision) << value << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "double: impossible" << std::endl;
    }
}

void ScalarConverter::convert(const std::string &str)
{
    if (str.empty() || hasMultipleDots(str))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    if (str == "-inff" || str == "+inff" || str == "nanf" ||
        str == "-inf" || str == "+inf" || str == "nan") 
    {
        handleSpecialCases(str);
        return;
    }
    if (isInteger(str) || isDouble(str) || isFloat(str) || isCharacter(str))
    {
        tryConvert(str);
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}