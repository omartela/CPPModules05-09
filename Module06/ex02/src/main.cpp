/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:32:32 by omartela          #+#    #+#             */
/*   Updated: 2025/03/04 09:32:34 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

#include <iostream>

Base *generate(void)
{
    int i = rand() % 3;

    if (i == 0)
    {
        std::cout << "A generated" << std::endl;
        return new A();
    }
    else if (i == 1)
    {
        std::cout << "B generated" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "C generated" << std::endl;
        return new C();
    }
}

void identify(Base *p)
{
    std::cout << "Pointer: ";
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify(Base &p)
{
    /// reference cannot be nullptr so only way to check fail is try catch
    std::cout << "Reference: ";
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::bad_cast &bc)
    {
        try
        {
            B &b = dynamic_cast<B &>(p);
            (void)b;
            std::cout << "B" << std::endl;
        }
        catch (std::bad_cast &bc)
        {
            try
            {
                C &c = dynamic_cast<C &>(p);
                (void)c;
                std::cout << "C" << std::endl;
            }
            catch (std::bad_cast &bc)
            {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}

int main()
{
    srand(time(NULL));

    Base *base = generate();
    identify(base);
    identify(*base);

    delete base;

    return 0;
}