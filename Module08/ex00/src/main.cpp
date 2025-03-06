/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:19:51 by omartela          #+#    #+#             */
/*   Updated: 2025/03/06 14:19:53 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <array>

int main()
{
	try
	{
		std::vector<int> vec = {1, 2, 3, 4, 5};
		easyfind(vec, 3);  // Should print "Found: 3"

		std::list<int> lst = {6, 7, 8, 9, 10};
		easyfind(lst, 8);  // Should print "Found: 8"

		//std::vector<double> vec_double = {1.1, 2.2, 3.3};
		//easyfind(vec_double, 2);
		/* std::vector<std::string> vec_str = {"test", "aa", "bb"};
		easyfind(vec_str, 2); */
		std::deque<int> deq = {11, 12, 13, 14, 15};
        easyfind(deq, 13);  // Should print "Found: 13"

		std::array<int, 5> arr = {16, 17, 18, 19, 20};
        easyfind(arr, 18);  // Should print "Found: 18"

		std::vector<int> emptyVec = {};
        easyfind(emptyVec, 1);  // Should throw an exception since the container is empty

	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}

    return 0;
}
