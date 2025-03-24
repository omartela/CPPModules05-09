/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:08:47 by omartela          #+#    #+#             */
/*   Updated: 2025/03/24 18:45:04 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
int main(int argc, char **argv)
{

    PmergeMe pmm;

    if (pmm.parseInput(argc, argv))
        return (1);
    pmm.mergeSort(static_cast<size_t>(1), false);
    // Prints the vector
    std::cout << "Sorted vector: ";
    pmm.printVector();
    return (0);
}