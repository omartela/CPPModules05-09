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
    Bureaucrat b1("B1", 1);
    Bureaucrat b2("B2", 150);
    Bureaucrat b3("B3", 75);
    Bureaucrat b4("B4", 1);
    Bureaucrat b5("B5", 150);
    Bureaucrat b6("B6", 75);

    RobotomyRequestForm r1("R1");
    PresidentialPardonForm p1("P1");
    ShrubberyCreationForm s1("S1");

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;
    std::cout << b4 << std::endl;
    std::cout << b5 << std::endl;
    std::cout << b6 << std::endl;

    std::cout << r1 << std::endl;
    std::cout << p1 << std::endl;
    std::cout << s1 << std::endl;

    b1.signForm(r1);
    b1.signForm(p1);
    b1.signForm(s1);

    b1.executeForm(r1);
    b1.executeForm(p1);
    b1.executeForm(s1);

    b2.signForm(r1);
    b2.signForm(p1);
    b2.signForm(s1);

    b2.executeForm(r1);
    b2.executeForm(p1);
    b2.executeForm(s1);

    b3.signForm(r1);
    b3.signForm(p1);
    b3.signForm(s1);

    b3.executeForm(r1);
    b3.executeForm(p1);
    b3.executeForm(s1);

    b4.signForm(r1);
    b4.signForm(p1);
    b4.signForm(s1);

    b4.executeForm(r1);
    b4.executeForm(p1);
    b4.executeForm(s1);

    b5.signForm(r1);
    b5.signForm(p1);
    b5.signForm(s1);

    b5.executeForm(r1);
    b5.executeForm(p1);
    b5.executeForm(s1);

    b6.signForm(r1);
    b6.signForm(p1);
    b6.signForm(s1);

    b6.executeForm(r1);
    b6.executeForm(p1);
    b6.executeForm(s1);
}