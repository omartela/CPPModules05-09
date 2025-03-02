/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:47:20 by omartela          #+#    #+#             */
/*   Updated: 2025/02/21 13:47:23 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Intern.hpp"


int main()
{
    Intern someRandomIntern;
    AForm* rrf;
    Bureaucrat boss("Boss", 1);

    try
    {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        rrf = someRandomIntern.makeForm("presidential pardon", "Alice");
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        rrf = someRandomIntern.makeForm("unknown form", "Target");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}