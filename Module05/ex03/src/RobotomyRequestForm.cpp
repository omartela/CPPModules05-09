/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:22:09 by omartela          #+#    #+#             */
/*   Updated: 2025/02/12 13:22:11 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"
#include <ctime>
#include "../inc/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
    if (this != &src)
    {
        _target = src._target;
    }
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (getSigned() == false)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    srand(time(NULL));
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << _target << " robotomization has failed." << std::endl;
}