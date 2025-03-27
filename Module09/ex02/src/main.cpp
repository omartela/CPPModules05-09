/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:08:47 by omartela          #+#    #+#             */
/*   Updated: 2025/03/27 11:29:51 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
#include <cmath>

size_t F(int n)
{
    size_t sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

int main(int argc, char **argv)
{

    PmergeMe pmm;

    if (!pmm.parseInput(argc, argv))
        return (1);
    pmm.mergeSort(static_cast<size_t>(1), false);
    pmm.mergeSortDeque(static_cast<size_t>(1), false);
    // Prints the vector
    std::cout << "Sorted vector: ";
    pmm.printVector();
    pmm.checkSorted();
    std::cout << "Sorted deque: ";
    pmm.printDeque();
    pmm.checkSortedDeque();

    std::cout << "Maximum amount of comparisons " << F(argc - 1) << std::endl;
    std::cout << "Total comparisons in sorting for vector " << pmm.get_nbr_of_comps() << std::endl;
    std::cout << "Total comparisons in sorting for deque " << pmm.get_nbr_of_comps_deque() << std::endl;
    return (0);
}