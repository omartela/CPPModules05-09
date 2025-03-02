/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 09:16:37 by omartela          #+#    #+#             */
/*   Updated: 2025/03/02 09:16:38 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class AForm;

class Intern
{
    public:
        Intern();
        Intern(Intern const &src);
        ~Intern();
        Intern & operator=(Intern const &src);

        AForm *makeForm(std::string form, std::string target);

        class FormNotFoundException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Form not found");
                }
        };
};
