/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:07:48 by omartela          #+#    #+#             */
/*   Updated: 2025/03/06 15:07:49 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>

class Span
{
	public:
		Span();
		Span(unsigned int n);
		~Span();
		Span(const Span& s);
		Span& operator=(const Span& s);
		void  addNumber(int number);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		void addRange(std::vector<int>::iterator first, std::vector<int>::iterator last);

	private:
		unsigned int _maximum;
		std::vector<int> _vector;
};