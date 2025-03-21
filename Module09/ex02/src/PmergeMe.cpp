/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:19:23 by omartela          #+#    #+#             */
/*   Updated: 2025/03/21 14:15:39 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
#include <sstream>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        this->_vec = src._vec;
    }
    return (*this);
}

bool PmergeMe::isValidValue(std::string value)
{
    std::stringstream ss(value); 
    int IntValue; 
    ss >> IntValue;
    if (!ss.eof())
        return (false);
    if (ss.fail() && ss.eof())
        return (false);
    if (IntValue < 0)
        return (false);
    return true;
}

int PmergeMe::ConvertValue(std::string str)
{
    std::stringstream ss(str); 
    int IntValue; 
    ss >> IntValue;
    return IntValue;
}

int PmergeMe::parseInput(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: ./PmergeMe [positive integers]" << std::endl;
        return (1);
    }
    else
    {
        char *str = argv[1];
        std::stringstream ss(str);
        std::string token;
        while (getline(ss, token, ' '))
        {
            if (!isValidValue(token))
            {
                std::cerr << "Error: invalid input" << std::endl;
                return (1);
            }
            else
            {
                _vec.push_back(ConvertValue(token));
            }
        }
    }
    return (0);
}

void PmergeMe::mergeSort(int pairsize, bool insert)
{
    if (insert == false)
    {
        for (int i = 0; i < _vec.size(); i += pairsize * 2)
        {
            int mid = i + pairsize;
            int end = std::min(i + pairsize * 2, (int)_vec.size());
            if (end == (int)_vec.size())
            {
                insert = true;
                break;
            }

            // Merge the two pairs
            std::vector<int> temp;
            int left = i, right = mid;

            // Compare the last elements of the two pairs
            if (mid - 1 < _vec.size() && end - 1 < _vec.size() && _vec[mid - 1] < _vec[end - 1])
            {
                // Swap the pairs if the last element of the right pair is smaller
                for (int k = 0; k < pairsize && mid + k < end; ++k)
                    std::swap(_vec[i + k], _vec[mid + k]);
            }
            mergeSort(pairsize * 2, false);
        }
    }
    else
    {
        
    }

}


