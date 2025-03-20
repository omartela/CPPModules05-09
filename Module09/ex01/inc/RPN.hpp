/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:46:08 by omartela          #+#    #+#             */
/*   Updated: 2025/03/20 14:30:37 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <iostream>

class RPN
{
    public:
        RPN();
        ~RPN();
        RPN(const RPN &src);
        RPN& operator=(const RPN &src);
        void calculate(std::string str);
        void  add(std::string str);

        int convertValue(std::string str);
        bool  isValidValue(std::string value);
        bool  isOperator(std::string str);
        int   getResult();
        double  getNoperands();
        double  getNoperators();
        void  incNoperands();
        void  incNoperators();
    

    private:
        std::stack<int> st;
        double Noperands; /// numbers
        double Noperators; /// - + / *

};

