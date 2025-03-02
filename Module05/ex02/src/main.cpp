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


int main()
{
    // Test case 1: ShrubberyCreationForm with valid Bureaucrat
    try
    {
        Bureaucrat b1("Alice", 1);
        ShrubberyCreationForm f1("home");
        b1.signForm(f1);
        b1.executeForm(f1);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // Test case 2: RobotomyRequestForm with valid Bureaucrat
    try
    {
        Bureaucrat b2("Bob", 1);
        RobotomyRequestForm f2("target");
        b2.signForm(f2);
        b2.executeForm(f2);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // Test case 3: PresidentialPardonForm with valid Bureaucrat
    try
    {
        Bureaucrat b3("Charlie", 1);
        PresidentialPardonForm f3("target");
        b3.signForm(f3);
        b3.executeForm(f3);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // Test case 4: ShrubberyCreationForm with Bureaucrat having too low grade to sign
    try
    {
        Bureaucrat b4("Dave", 150);
        ShrubberyCreationForm f4("home");
        b4.signForm(f4);
        b4.executeForm(f4);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // Test case 5: RobotomyRequestForm with Bureaucrat having too low grade to execute
    try
    {
        Bureaucrat b5("Eve", 72);
        RobotomyRequestForm f5("target");
        b5.signForm(f5);
        b5.executeForm(f5);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // Test case 6: PresidentialPardonForm with Bureaucrat having too low grade to sign
    try
    {
        Bureaucrat b6("Frank", 26);
        PresidentialPardonForm f6("target");
        b6.signForm(f6);
        b6.executeForm(f6);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}