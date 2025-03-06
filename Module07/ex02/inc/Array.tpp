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
#include "Array.hpp"

template <typename T>
Array<T>::Array() : length(0), array(nullptr) {}

template <typename T>
Array<T>::Array(const unsigned int n)
{
	length = n;
	array = new T[n]();
}

template <typename T>
Array<T>::~Array()
{
	delete[] array;
}

template <typename T>
Array<T>::Array(Array const &src)
{
	if (src.size() != 0)
	{
		length = src.size();
		array = new T[length];
		for (unsigned int i = 0; i < length; ++i)
    	{
        	array[i] = src.array[i];
    	}
	}
	else
	{
		this->length = 0;
		this->array = nullptr;
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &arr)
{
	if (this != &arr)
	{
		delete[] *this;

		length = arr.size();
		array = new T[length];
		for (unsigned int i = 0; i < length; ++i)
		{
			array[i] = arr.array[i];
		}
	}
	return *this;
}


template <typename T>
unsigned int Array<T>::size() const
{
    return length;
}


template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= size()) 
	{
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= size()) 
	{
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}
