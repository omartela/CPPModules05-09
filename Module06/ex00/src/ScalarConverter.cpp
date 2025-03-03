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

bool ScalarConverter::hasMultipleDots(const std::string &str)
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

int ScalarConverter::getPrecision(const std::string &str)
{
    size_t dotPos = str.find('.');
    if (dotPos == std::string::npos)
        return 1;

    size_t endPos = str.find('f', dotPos);
    if (endPos == std::string::npos || endPos != str.length() - 1)
        endPos = str.length();

    return endPos - dotPos - 1;
}

bool ScalarConverter::isChar(const std::string &str)
{
    if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(static_cast<unsigned char>(str[0])))
		return true;
    return false;
}

bool ScalarConverter::isInf(const std::string &str)
{
    return str == "-inff" || str == "+inff" || str == "-inf" || str == "+inf";
}

bool ScalarConverter::isNan(const std::string &str)
{
    return str == "nanf" || str == "nan";
}

bool ScalarConverter::isInt(const std::string &str)
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

bool ScalarConverter::isFloat(const std::string &str)
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

bool ScalarConverter::isDouble(const std::string &str)
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

void ScalarConverter::convertChar(const std::string &str)
{
    if (str.length() == 1 && std::isprint(str[0]))
        std::cout << "char: '" << str[0] << "'" << std::endl;
    else if (str.length() == 1)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
}

void ScalarConverter::convertInt(const std::string &str)
{
    try
    {
        int i = std::stoi(str);
        std::cout << "int: " << i << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "int: impossible" << std::endl;
    }
}

void ScalarConverter::convertFloat(const std::string &str)
{
    try
    {
        float f = std::stof(str);
        int precision = getPrecision(str);
        std::cout << "float: " << std::fixed << std::setprecision(precision) << f << "f" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "float: impossible" << std::endl;
    }
}

void ScalarConverter::convertDouble(const std::string &str)
{
    try
    {
        double d = std::stod(str);
        int precision = getPrecision(str);
        std::cout << "double: " << std::fixed << std::setprecision(precision) << d << std::endl;
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

    if (isInf(str) || isNan(str))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (str.back() == 'f')
        {
            std::cout << "float: " << str << std::endl;
            std::cout << "double: " << str.substr(0, str.size() - 1) << std::endl;
        }
        else
        {
            std::cout << "float: " << str << "f" << std::endl;
            std::cout << "double: " << str << std::endl;
        }
        return;
    }

    bool (*checkers[4]) (const std::string &str)= {
        isChar,
        isInt,
        isFloat,
        isDouble,
    };
    void (*converters[4]) (const std::string &str)= {
        convertChar,
        convertInt,
        convertFloat,
        convertDouble
    };

    for (size_t i = 0; i < 4; ++i)
    {
        if (checkers[i](str))
        {
            converters[i](str);
        }
        else if (i == 0)
        {
            if (str.length() == 1)
            {
                int i = std::stoi(str);
                if (!std::isprint(i))
                {
                    std::cout << "char: Non displayable" << std::endl;
                }
                else
                    std::cout << "char: impossible" << std::endl;
            }
            else
                std::cout << "char: impossible" << std::endl;
        }
        else if (i == 1)
        {
            std::cout << "int: impossible" << std::endl;
        }
        else if (i == 2)
        {
            std::cout << "float: impossible" << std::endl;
        }
        else if (i == 3)
        {
            std::cout << "double: impossible" << std::endl;
        }
    }
}