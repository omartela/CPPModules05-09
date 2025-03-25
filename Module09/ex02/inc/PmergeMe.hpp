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
#include <iostream>

class PmergeMe
{
private:
    static int nbr_of_comps;
    std::vector<int> _vec;
    size_t _jbth;
    size_t _jbthprevious;
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
    void printVector();
    bool checkSorted();
};

template <typename T> bool _comp(T lv, T rv) 
{
    PmergeMe::nbr_of_comps++;
    return *lv < *rv;
}
