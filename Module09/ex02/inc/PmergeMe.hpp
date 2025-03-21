/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:17:17 by omartela          #+#    #+#             */
/*   Updated: 2025/03/21 14:02:44 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <iostream>

class PmergeMe
{
private:
    std::vector<int> _vec;
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &src);
    PmergeMe& operator=(const PmergeMe &src);
    bool isValidValue(std::string value);
    int ConvertValue(std::string str);
    int parseInput(int argc, char **argv);
    void mergeSort();
};

