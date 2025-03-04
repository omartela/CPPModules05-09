/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:58:08 by omartela          #+#    #+#             */
/*   Updated: 2025/03/04 08:58:09 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdint>

struct Data
{
    std::string s1;
    int n;
    std::string s2;
};

class Serializer
{
    public:
        static uintptr_t serialize(Data *data);
        static Data *deserialize(uintptr_t raw);

    private:
        Serializer() = delete;
        Serializer(Serializer const & src) = delete;
        ~Serializer() = delete;
        Serializer & operator=(Serializer const & rhs) = delete;
};

