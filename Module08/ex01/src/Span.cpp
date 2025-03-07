/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:08:02 by omartela          #+#    #+#             */
/*   Updated: 2025/03/06 15:08:03 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
#include <algorithm>

Span::Span(): _maximum(0) {}

Span::Span(unsigned int n) : _maximum(n) {}

Span::~Span() {}

Span::Span(Span const &src)
{
	if (this != &src)
	{
		_maximum = src._maximum;
		_vector = src._vector;
	}
}

Span &Span::operator=(Span const &src)
{
	if (this != &src)
	{
		_maximum = src._maximum;
		_vector = src._vector;
	}
	return (*this);
}

void Span::addNumber(int number)
{
	if (_vector.size() < _maximum)
	{
		_vector.push_back(number);
	}
	else
	{
		throw std::runtime_error("Cannot add elements, span is full");
	}
}

unsigned int Span::shortestSpan()
{
	if (_vector.size() < 2)
		throw std::runtime_error("Cannot calculate shortest span because the size is less than 2");
	std::vector<int> copyvector;
	copyvector = _vector;
	std::sort(copyvector.begin(), copyvector.end());

	unsigned int min_span = std::abs(copyvector[1] - copyvector[0]);
	for (auto it = copyvector.begin(); it != copyvector.end() - 1; ++it) 
	{
        unsigned int span = std::abs(*(std::next(it)) - *it);
        min_span = std::min(min_span, span);
    }
	return (min_span);
}

unsigned int Span::longestSpan()
{
	if (_vector.size() < 2)
		throw std::runtime_error("Cannot calculate longest span because the size is less than 2");
	auto min_max = std::minmax_element(_vector.begin(), _vector.end());
	unsigned int span = *min_max.second - *min_max.first;
	return span;
}

void Span::addRange(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	size_t range_size = std::distance(first, last);
	if (_vector.size() + range_size > _maximum)
		throw std::runtime_error("Cannot add elements, capacity exceeded");
	_vector.insert(_vector.end(), first, last);
}

