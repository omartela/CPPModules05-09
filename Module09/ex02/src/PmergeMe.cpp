/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:19:23 by omartela          #+#    #+#             */
/*   Updated: 2025/03/24 18:44:12 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
#include <sstream>
#include <algorithm>
#include <math.h>

size_t PmergeMe::nbr_of_comps = 0;

void PmergeMe::incr_nbr_of_comps()
{
    nbr_of_comps++;
}

size_t PmergeMe::get_nbr_of_comps()
{
    return (nbr_of_comps);
}

PmergeMe::PmergeMe() 
{
    _jbth = static_cast<size_t>(3);
    _jbthprevious = static_cast<size_t>(1);
}

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

bool PmergeMe::checkSorted()
{
    for (size_t i = 1; i < _vec.size(); i++)
    {
        if (_vec[i - 1] > _vec[i])
        {
            std::cout << i << std::endl;
            std::cout << "_vec[i - 1] = " << _vec[i - 1] << std::endl;
            std::cout << "_vec[i] = " << _vec[i] << std::endl;
            std::cout << "not sorted " << std::endl;
            return false;
        }
    }
    std::cout << "Sort OK!" << std::endl;
    return true;
}

void PmergeMe::printVector()
{
    for (size_t i = 0; i < _vec.size(); ++i)
    {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;
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

bool PmergeMe::parseInput(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: ./PmergeMe [positive integers]" << std::endl;
        return (1);
    }
    else
    {
        int i = 1;
        while (argv[i])
        {
            if (!isValidValue(argv[i]))
            {
                std::cerr << "Error: invalid input" << std::endl;
                return (1);
            }
            else
            {
                std::vector<int>::iterator it;
                it = std::find(_vec.begin(), _vec.end(), ConvertValue(argv[i]));
                if (it != _vec.end())
                {
                    std::cout << "Duplicates are not allowed, Duplicate element: " << *it << std::endl;
                    return (false);
                }
                _vec.push_back(ConvertValue(argv[i]));
            }
            i++;
        }
    }
    return (true);
}

size_t PmergeMe::calcJacobsthal(size_t current)
{
    // The first two Jacobsthal numbers are 0 and 1
    if (current == 0)
        return 0; // J(1)
    if (current == 1)
        return 1; // J(2)
    
    size_t prev = 0;
    size_t currentValue = 1;

    // Continue generating the sequence until we find the correct current
    while (true)
    {
        size_t nextValue = currentValue + 2 * prev; // Calculate next Jacobsthal number
        if (currentValue == current)
        {
            return nextValue; // Return the next number
        }

        // Update for next iteration
        prev = currentValue;
        currentValue = nextValue;
    }
}

void PmergeMe::mergeSort(size_t pairsize, bool insert)
{
    if (insert == false)
    {
        for (size_t i = 0; i < _vec.size(); i += pairsize * 2)
        {
            size_t mid = i + pairsize;
            size_t end = std::min(i + pairsize * 2, (size_t)_vec.size());
            if (_vec.size() / 2 < pairsize) 
            {
                insert = true;
                return;
            }
            if (i + pairsize * 2 > (size_t)_vec.size())
            {
                break;
            }

            // Compare the last elements of the two pairs
            if (mid - 1 < _vec.size() && end - 1 < _vec.size() && _comp(_vec[end - 1], _vec[mid - 1]))
            {
                // Swap the pairs if the last element of the right pair is smaller
                for (size_t k = 0; k < pairsize && mid + k < end; ++k)
                    std::swap(_vec[i + k], _vec[mid + k]);
            }
        }
        mergeSort(pairsize * 2, insert);
    }
    /// convert _vector to 2d vector with pairsize to temp
    std::vector<std::vector<int>> temp;  

    for (size_t i = 0; i < _vec.size(); i += pairsize)  
    {  
        std::vector<int> chunk;  
        
        // Kopioidaan seuraavat "pairsize" alkioita tai loput, jos ei riitä täyttä lohkoa  
        for (size_t j = i; j < i + pairsize && j < _vec.size() && i + pairsize <= _vec.size(); ++j)  
        {  
            chunk.push_back(_vec[j]);  
        }  
        if (!chunk.empty())
            temp.push_back(chunk);  // Lisätään lohko temp-vektoriin  
    }


    std::vector<std::vector<int>> pend; // pend is b2 and rest of b:s
    std::vector<std::vector<int>> main; // main is b1 and rest of a:s

    for (size_t i = 0; i < temp.size(); ++i)
    {
        if (i == 0)
        {
            // Ensimmäinen pari (b1) menee MAIN-vektoriin
            main.push_back(temp[i]);
        }
        else if (i % 2 == 0)
        {
            // Jokainen parillinen indeksi (b2, b3, ...) menee PEND-vektoriin
            pend.push_back(temp[i]);
        }
        else
        {
            // Jokainen pariton indeksi (a1, a2, ...) menee MAIN-vektoriin
            main.push_back(temp[i]);
        }
    }
    size_t boundElement;
    // Start inserting from pend to main
    // Check bound element... for example b3 bound element in main is a3
    // bound element marks the search area.
    // jacobsthal number - 2 is the correct index of b element in the pend vector
    while (pend.size() > 0)
    {
        for (size_t i = 0; i < (_jbth - _jbthprevious); ++i)
        {
            std::vector<int> elementtoinsert;
            if (pend.size() > 1)
            {
                if (pend.size() - 1 > _jbth - 2)
                {
                    elementtoinsert = pend[_jbth - 2 - i];
                }
                else
                {
                    // we ran out of jacobsthal numbers.. meaning we have still elements to insert
                    // but it does not to correspond to the jacobsthal number
                    // for example we have b6 and jacobsthal number is 11 so it its not 6.
                    elementtoinsert = pend[pend.size() - 1];
                }
            }
            else
                elementtoinsert = pend[0];
            // Find the bound element
            for (size_t j = 0; j < temp.size(); ++j)
            {
                if (temp[j] == elementtoinsert)
                {
                    if (j + 1 < temp.size())
                    {
                        for (size_t k = 0; k < main.size(); ++k)
                        {
                            if (main[k] == temp[j + 1])
                            {
                                boundElement = k;
                                break;
                            }
                        }
                    }
                    else
                        boundElement = 0;
                    break;
                }
            }
            // Insert the element to the correct place

            /// there is still something wrong with calculating the bound element check it tomorrow
            size_t bound;
            bool inserted = false;
            if (boundElement == 0)
                bound = main.size(); /// otherwise the main.begin() + bound is out of bounds
            else
                bound = boundElement; /// needs to be -1 otherwise it will include the bound element also in to the search.
            
            auto it = std::lower_bound(main.begin(), main.begin() + bound, elementtoinsert, 
            [pairsize](const std::vector<int>& a, const std::vector<int>& b) {
                // Here, compare the pairsize - 1th element of each vector
                return _comp(a[pairsize - 1], b[pairsize - 1]); 
            });

            std::vector<std::vector<int>>::iterator it2;
            it2 = std::find(pend.begin(), pend.end(), elementtoinsert);
            if (it2 == pend.end())
            {
                std::cout << pairsize << std::endl;
                std::cout << "Element to insert was not found in pend" << std::endl;
                return;
            }
            if (it != main.begin() + bound)
            {
                main.insert(it, elementtoinsert);
                inserted = true;
                if (it2 != pend.end())
                    pend.erase(it2);
            }
            if (inserted == false)
            {
                if (boundElement)
                    main.insert(main.begin() + bound, elementtoinsert);
                else
                    main.push_back(elementtoinsert);
                if (it2 != pend.end())
                    pend.erase(it2);
            }
            if (pend.size() == 0)
            {
                // ovewrite main elements to _vec
                size_t k = 0;
                for (size_t j = 0; j < main.size(); ++j)
                {
                    for (size_t l = 0; l < main[j].size(); ++l)
                    {
                        _vec[k] = main[j][l];
                        k++;
                    }
                }
                return;
            }
        }
        _jbthprevious = _jbth;
        _jbth = calcJacobsthal(_jbth);
    }
}


