/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:17:17 by omartela          #+#    #+#             */
/*   Updated: 2025/03/24 18:43:21 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <deque>
#include <iostream>

class PmergeMe
{
private:
    std::vector<int> _vec;
    std::deque<int> _deq;
    size_t _jbth;
    size_t _jbthprevious;
    size_t _jbthdeq;
    size_t _jbthpreviousdeq;
    static size_t nbr_of_comps;
    static size_t nbr_of_comps_deque;
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &src);
    PmergeMe& operator=(const PmergeMe &src);
    bool isValidValue(std::string value);
    int ConvertValue(std::string str);
    bool parseInput(int argc, char **argv);
    size_t calcJacobsthal(size_t current);
    void mergeSort(size_t pairsize, bool insert);
    void mergeSortDeque(size_t pairsize, bool insert);
    void printVector();
    void printDeque();
    bool checkSorted();
    bool checkSortedDeque();
    static void incr_nbr_of_comps();
    static void incr_nbr_of_comps_deque();
    static size_t get_nbr_of_comps();
    static size_t get_nbr_of_comps_deque();
};

template <typename T> bool _comp(T lv, T rv) 
{
    PmergeMe::incr_nbr_of_comps();
    return lv < rv;
}

template <typename T> bool _comp_deque(T lv, T rv) 
{
    PmergeMe::incr_nbr_of_comps_deque();
    return lv < rv;
}

template <typename T> void _print_sequence(T &a, size_t len, size_t pairsize)
{
    for (size_t i = 0; i < len; ++i)
    {
        for (size_t j = 0; j < pairsize; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;   
}