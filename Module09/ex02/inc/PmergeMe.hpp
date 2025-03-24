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
    int parseInput(int argc, char **argv);
    int calcJacobsthal(int n);
    void mergeSort(size_t pairsize, bool insert);
    void printVector();
};

