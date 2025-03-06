/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:44:52 by omartela          #+#    #+#             */
/*   Updated: 2025/03/05 11:44:53 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>

template <typename T, typename F>
void iter(T* array, size_t length, F func) 
{
    if (!array)
        return;
    for (size_t i = 0; i < length; ++i) 
    {
        func(array[i]);
    }
}