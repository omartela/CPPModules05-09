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
#include "../inc/Form.hpp"

int main()
{
    // Test case 1: Bureaucrat with valid grade signing a form with valid grade requirements
    try
    {
        Bureaucrat b1("Alice", 5);
        Form f1("FormA", 10, 10);
        b1.signForm(f1);
        std::cout << f1 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // Test case 2: Bureaucrat with too low grade trying to sign a form
    try
    {
        Bureaucrat b2("Bob", 15);
        Form f2("FormB", 10, 10);
        b2.signForm(f2);
        std::cout << f2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // Test case 3: Bureaucrat with equal grade trying to sign a form
    try
    {
        Bureaucrat b3("Charlie", 1);
        Form f3("FormC", 1, 1);
        b3.signForm(f3);
        std::cout << f3 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // Test case 4: Creating a form with invalid grade (too high)
    try
    {
        Form f4("FormD", 0, 10);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // Test case 5: Creating a form with invalid grade (too low)
    try
    {
        Form f5("FormE", 10, 151);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}