/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:10:15 by omartela          #+#    #+#             */
/*   Updated: 2025/02/07 17:10:18 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        bool _signed;
        int const _signGrade;
        int const _execGrade;
    public:
        Form();
        Form(std::string name, int signGrade, int execGrade);
        Form(Form const &src);
        ~Form();
        Form &operator=(Form const &src);
        std::string getName() const;
        bool getSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        void beSigned(Bureaucrat &b);
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, Form const &src);