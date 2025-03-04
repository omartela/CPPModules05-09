/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:56:43 by omartela          #+#    #+#             */
/*   Updated: 2025/03/04 08:56:45 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "../inc/Serializer.hpp"

int main()
{
    Data data;
    uintptr_t raw;

    data.s1 = "Hello";
    data.n = 42;
    data.s2 = "World";

    std::cout << "Data before serialization:" << std::endl;
    std::cout << "s1: " << data.s1 << std::endl;
    std::cout << "n: " << data.n << std::endl;
    std::cout << "s2: " << data.s2 << std::endl;

    raw = Serializer::serialize(&data);

    Data *data2 = Serializer::deserialize(raw);

    std::cout << "Data after deserialization:" << std::endl;
    std::cout << "s1: " << data2->s1 << std::endl;
    std::cout << "n: " << data2->n << std::endl;
    std::cout << "s2: " << data2->s2 << std::endl;

    if (&data == data2)
    {
        std::cout << "Pointer comparison: Success" << std::endl;
    }
    else
    {
        std::cout << "Pointer comparison: Failure" << std::endl;
    }

    Data edgeCaseData;
    edgeCaseData.s1 = "";
    edgeCaseData.n = -1;
    edgeCaseData.s2 = "";

    raw = Serializer::serialize(&edgeCaseData);
    Data *edgeCaseData2 = Serializer::deserialize(raw);

    std::cout << "Data after deserialization:" << std::endl;
    std::cout << "s1: " << edgeCaseData2->s1 << std::endl;
    std::cout << "n: " << edgeCaseData2->n << std::endl;
    std::cout << "s2: " << edgeCaseData2->s2 << std::endl;

    return 0;
}
