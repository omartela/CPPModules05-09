/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 09:16:49 by omartela          #+#    #+#             */
/*   Updated: 2025/03/02 09:16:50 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &src)
{
    *this = src;
}

Intern::~Intern() {}

Intern & Intern::operator=(Intern const &src)
{
    (void)src;
    return (*this);
}

AForm* createRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* createShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string form, std::string target)
{
    std::string formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    AForm* (*formCreators[3])(std::string target) = {
        createRobotomyRequestForm,
        createPresidentialPardonForm,
        createShrubberyCreationForm
    };

    for (int i = 0; i < 3; i++)
    {
        if (form == formNames[i])
        {
            std::cout << "Intern creates " << formNames[i] << std::endl;
            return formCreators[i](target);
        }
    }
    throw Intern::FormNotFoundException();
    return NULL;
}
