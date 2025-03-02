/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:25:28 by omartela          #+#    #+#             */
/*   Updated: 2025/03/02 10:25:29 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>

class ScalarConverter
{
    public:
        static void convert(const std::string &str);
        static bool hasMultipleDots(const std::string &str);
        static bool isInf(const std::string &str);
        static bool isNan(const std::string &str);
        static bool isChar(const std::string &str);
        static bool isInt(const std::string &str);
        static bool isFloat(const std::string &str);
        static bool isDouble(const std::string &str);
        static void convertChar(const std::string &str);
        static void convertInt(const std::string &str);
        static void convertFloat(const std::string &str);
        static void convertDouble(const std::string &str);
        static int getPrecision(const std::string &str);

    private:
        ScalarConverter() = delete;
        ScalarConverter(const ScalarConverter &src) = delete;
        ScalarConverter &operator=(const ScalarConverter &src) = delete;
        ~ScalarConverter() = delete;
};