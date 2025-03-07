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
#include <algorithm>

template <typename T> int easyfind(T container, int n)
{
	auto it = std::find(container.begin(), container.end(), n);
	if (it != container.end())
	{
		std::cout << "Found " << *it << std::endl;
		return *it;
	}
	else
		throw std::runtime_error("Value cannot be found in the container");
}
