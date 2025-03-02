/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:16:35 by omartela          #+#    #+#             */
/*   Updated: 2025/02/07 17:16:36 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form() : _name("default"), _signed(false), _signGrade(150), _execGrade(150) {}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (_signGrade < 1 || _execGrade < 1)
        throw Form::GradeTooLowException();
    if (_signGrade > 150 || _execGrade > 150)
        throw Form::GradeTooHighException();
}

Form::Form(Form const &src) : _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade) {}

Form::~Form() {}

Form & Form::operator=(Form const &src)
{
    if (this != &src)
    {
        _signed = src._signed;
    }
    return (*this);
}

std::string Form::getName() const
{
    return (_name);
}

bool Form::getSigned() const
{
    return (_signed);
}

int Form::getSignGrade() const
{
    return (_signGrade);
}

int Form::getExecGrade() const
{
    return (_execGrade);
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > _signGrade)
        throw Form::GradeTooLowException();
    _signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}

const char* Form::FormNotSignedException::what() const throw()
{
    return ("Form is not signed!");
}

std::ostream &operator<<(std::ostream &os, Form const &src)
{
    os << "Form: " << src.getName() << " is ";
    if (src.getSigned())
        os << "signed";
    else
        os << "not signed";
    os << " and requires grade " << src.getSignGrade() << " to sign and grade " << src.getExecGrade() << " to execute." << std::endl;
    return (os);
}


