/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:39:46 by omartela          #+#    #+#             */
/*   Updated: 2025/02/07 16:39:47 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("b1", 0);
    }
    catch (const Bureaucrat::GradeTooHighException & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b2("b2", 151);
    }
    catch (const Bureaucrat::GradeTooLowException & e)
    {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat b3("b3", 1);
    std::cout << b3 << std::endl;
    b3.decrementGrade();
    std::cout << b3 << std::endl;
    b3.incrementGrade();
    std::cout << b3 << std::endl;

    try 
    {
        Bureaucrat b4("b4", 150);
        std::cout << b4 << std::endl;
        b4.decrementGrade();
    }
    catch (const Bureaucrat::GradeTooLowException & e)
    {
        std::cout << e.what() << std::endl;
    }

     try 
    {
        Bureaucrat b4("b4", 1);
        std::cout << b4 << std::endl;
        b4.incrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException & e)
    {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat b5("b5", 100);
    std::cout << b5 << std::endl;

    return (0);
}