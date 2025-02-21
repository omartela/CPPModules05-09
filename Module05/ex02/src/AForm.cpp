/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:16:35 by omartela          #+#    #+#             */
/*   Updated: 2025/02/07 17:16:36 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (_signGrade < 1 || _execGrade < 1)
        throw AForm::GradeTooLowException();
    if (_signGrade > 150 || _execGrade > 150)
        throw AForm::GradeTooHighException();
}

AForm::AForm(AForm const &src) : _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade) {}

AForm::~AForm() {}

AForm & AForm::operator=(AForm const &src)
{
    if (this != &src)
    {
        _signed = src._signed;
    }
    return (*this);
}

std::string AForm::getName() const
{
    return (_name);
}

bool AForm::getSigned() const
{
    return (_signed);
}

int AForm::getSignGrade() const
{
    return (_signGrade);
}

int AForm::getExecGrade() const
{
    return (_execGrade);
}

void AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() < _signGrade)
        throw AForm::GradeTooLowException();
    _signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("AForm is not signed!");
}

std::ostream &operator<<(std::ostream &os, AForm const &src)
{
    os << "AForm: " << src.getName() << " is ";
    if (src.getSigned())
        os << "signed";
    else
        os << "not signed";
    os << " and requires grade " << src.getSignGrade() << " to sign and grade " << src.getExecGrade() << " to execute." << std::endl;
    return (os);
}


