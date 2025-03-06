/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:20:12 by omartela          #+#    #+#             */
/*   Updated: 2025/03/06 14:20:14 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T> int easyfind(T container, int n)
{
	auto it = container.begin();
	while (it != container.end())
	{
		if (*it == n)
		{
			std::cout << "Found " << *it << std::endl;
			return *it;
		}
		it++;
	}
	throw std::runtime_error("Value cannot be found in the container");
}
