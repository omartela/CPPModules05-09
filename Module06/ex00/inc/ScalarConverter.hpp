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
#include <limits.h>
#include <limits>
#include <cmath>

class ScalarConverter
{
    public:
        static void convert(const std::string &str);

    private:
        ScalarConverter() = delete;
        ScalarConverter(const ScalarConverter &src) = delete;
        ScalarConverter &operator=(const ScalarConverter &src) = delete;
        ~ScalarConverter() = delete;
};