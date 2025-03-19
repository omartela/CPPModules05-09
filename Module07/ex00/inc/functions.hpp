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
    T temp; /// Need to do like this and not T temp = a; because otherwise the compiler does not know which copy assigment operator to use the implicit one or the one defined in class
    temp = a;
    a = b;
    b = temp;
}

template <class T>
T const &min (const T &a, const T &b)
{
    if (a == b)
        return b;
    if (a < b)
        return a;
    else
        return b;
}

template <class T>
T const &max (const T &a, const T &b)
{
    if (a == b)
        return b;
    if (a > b)
        return a;
    else
        return b;
}

