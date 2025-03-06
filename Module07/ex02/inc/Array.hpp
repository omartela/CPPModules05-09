/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:35:54 by omartela          #+#    #+#             */
/*   Updated: 2025/03/05 12:35:55 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <exception>

template <typename T> class Array
{
	public:
		Array();
		Array(const unsigned int n);
		Array(const Array& newarray);
		~Array();
		Array &operator=(const Array& arr);
		T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const; 
		unsigned int	size() const;

	private:
		unsigned int length;
		T *array;

};