/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:24:49 by omartela          #+#    #+#             */
/*   Updated: 2025/03/05 11:24:50 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <class T>
void swap (T &a, T &b) 
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
T min (const T &a, const T &b)
{
    if (a == b)
        return b;
    if (a < b)
        return a;
    else
        return b;
}

template <class T>
T max (const T &a, const T &b)
{
    if (a == b)
        return b;
    if (a > b)
        return a;
    else
        return b;
}

