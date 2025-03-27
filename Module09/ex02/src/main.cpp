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
#include <chrono>

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

    if (argc < 2)
    {
        std::cout << "Usage: ./PmergeMe [positive integers]" << std::endl;
        return (1);
    }

    auto startparsevec = std::chrono::high_resolution_clock::now();
    if (!pmm.parseInput(argv))
        return (1);
    auto stopparsevec = std::chrono::high_resolution_clock::now();
    auto durationparsevec = std::chrono::duration_cast<std::chrono::microseconds>(stopparsevec - startparsevec);

    auto startparsedeque = std::chrono::high_resolution_clock::now();
    if (!pmm.parseInputDeque(argv))
        return (1);
    auto stopparsedeque = std::chrono::high_resolution_clock::now();
    auto durationparsedeque = std::chrono::duration_cast<std::chrono::microseconds>(stopparsedeque - startparsedeque);
    auto startvector = std::chrono::high_resolution_clock::now();

    std::cout << "Before: ";
    pmm.printVector();

    pmm.mergeSort(static_cast<size_t>(1), false);
    auto stopvector = std::chrono::high_resolution_clock::now();
    auto durationvector = std::chrono::duration_cast<std::chrono::microseconds>(stopvector - startvector);
    auto startdeque = std::chrono::high_resolution_clock::now();
    pmm.mergeSortDeque(static_cast<size_t>(1), false);
    auto stopdeque = std::chrono::high_resolution_clock::now();
    auto durationdeque = std::chrono::duration_cast<std::chrono::microseconds>(stopdeque - startdeque);
    // Prints the vector
    std::cout << "After: ";
    pmm.printVector();
    //pmm.checkSorted();
   /*  std::cout << "Sorted deque: ";
    pmm.printDeque(); */
    //pmm.checkSortedDeque();

   /*  std::cout << "Maximum amount of comparisons " << F(argc - 1) << std::endl;
    std::cout << "Total comparisons in sorting for vector " << pmm.get_nbr_of_comps() << std::endl;
    std::cout << "Total comparisons in sorting for deque " << pmm.get_nbr_of_comps_deque() << std::endl; */
    return (0);
}