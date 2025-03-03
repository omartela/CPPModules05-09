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

int getPrecision(const std::string &str)
{
    size_t dotPos = str.find('.');
    if (dotPos == std::string::npos)
        return 1;

    size_t endPos = str.find('f', dotPos);
    if (endPos == std::string::npos || endPos != str.length() - 1)
        endPos = str.length();

    return endPos - dotPos - 1;
}

bool isChar(const std::string &str)
{
    if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(static_cast<unsigned char>(str[0])))
		return true;
    return false;
}

bool isInt(const std::string &str)
{
    if (str.empty())
        return false;

    size_t start = 0;
    if ((str[0] == '-' || str[0] == '+') && str.length() > 1)
        start = 1;

    for (size_t i = start; i < str.length(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])) || str[i] == '.')
            return false;
    }
    return true;
}

bool isFloat(const std::string &str)
{
    if (str.empty())
        return false;

    size_t start = 0;
    int    fflag = 0;
    if ((str[0] == '-' || str[0] == '+') && str.length() > 1)
        start = 1;
    for (size_t i = start; i < str.length(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
        {
            if (str[i] == '.')
                continue;
            if (str[i] == 'f')
            {
                if (fflag == 0)
                    fflag = 1;
                else
                    return false;
            }
            else
                return false;
        }
    }
    if (fflag == 1 && str[str.length() - 1] != 'f')
        return false;
    return true;
}

bool isDouble(const std::string &str)
{
    if (str.empty())
        return false;

    size_t start = 0;
    if ((str[0] == '-' || str[0] == '+') && str.length() > 1)
        start = 1;

    for (size_t i = start; i < str.length(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
        {
            if (str[i] == '.')
                continue;
            else
                return false;
        }
    }
    return true;
}


static void handleSpecialCases(const std::string &str) 
{
        if (str == "-inff" || str == "+inff") 
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << str << std::endl;
            std::cout << "double: " << (str == "-inff" ? "-inf" : "+inf") << std::endl;
        } else if (str == "nanf" || str == "nan") 
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << str << std::endl;
            std::cout << "double: " << str << std::endl;
        }
}

static void handleInt(int value, int precision) 
{
    std::cout << "char: ";
    if (value >= CHAR_MIN && CHAR_MAX <= 255 && isprint(value)) {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    } else {
        std::cout << "Non displayable" << std::endl;
    }
    std::cout << "int: " << std::fixed << std::setprecision(precision) << value << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(precision) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(precision) << static_cast<double>(value) << std::endl;
}

static void handleFloat(float value, int precision) 
{
    std::cout << "char: ";
    if (value >= CHAR_MIN && value <= CHAR_MAX && isprint(static_cast<int>(value))) 
    {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    } 
    else 
    {
        std::cout << "Non displayable" << std::endl;
    }
    if (value < static_cast<float>(std::numeric_limits<int>::max()) && 
        value > static_cast<float>(std::numeric_limits<int>::min()))
    {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
    std::cout << "float: " << std::fixed << std::setprecision(precision) << value << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(precision) << static_cast<double>(value) << std::endl;
}

static void handleDouble(double value, int precision) 
{
    std::cout << "char: ";
    if (value >= CHAR_MIN && value <= CHAR_MAX && isprint(static_cast<int>(value))) 
    {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    } 
    else 
    {
        std::cout << "Non displayable" << std::endl;
    }
    if (value < static_cast<double>(std::numeric_limits<int>::max()) && 
        value > static_cast<double>(std::numeric_limits<int>::min()))
    {
        std::cout << "int: " << std::fixed << std::setprecision(precision) << static_cast<int>(value) << std::endl;
    }
    if (value < static_cast<double>(std::numeric_limits<float>::max()) && 
        value > static_cast<double>(std::numeric_limits<float>::min()))
    {
        std::cout << "float: " << std::fixed << std::setprecision(precision) << static_cast<float>(value) << "f" << std::endl;
    }
    std::cout << "double: " << std::fixed << std::setprecision(precision) << value << std::endl;
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
    int precision = getPrecision(str);
    try 
    {
        int intValue = std::stoi(str);
        handleInt(intValue, precision);
        return;
    } catch (...) 
    {
        std::cout << "int: impossible" << std::endl;
    }
    try 
    {
        float floatValue = std::stof(str);
        handleFloat(floatValue, precision);
        return;
    } catch (...) 
    {
        std::cout << "float: impossible" << std::endl;
    }
    try 
    {
        double doubleValue = std::stod(str);
        handleDouble(doubleValue, precision);
        return;
    } catch (...) 
    {
        std::cout << "double: impossible" << str << std::endl;
    }
}