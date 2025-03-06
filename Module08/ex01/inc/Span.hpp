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

#include <iostream>

class Span
{
	public:
		Span();
		Span(unsigned int n);
		~Span();
		Span(const Span& s);
		Span& operator=(const Span& s);
	private:
		unsigned int maximum;
};