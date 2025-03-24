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

int PmergeMe::parseInput(int argc, char **argv)
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
                _vec.push_back(ConvertValue(argv[i]));
            }
            i++;
        }
    }
    return (0);
}

int PmergeMe::calcJacobsthal(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return (2 * calcJacobsthal(n - 1) + calcJacobsthal(n - 2));
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
            if (mid - 1 < _vec.size() && end - 1 < _vec.size() && _vec[mid - 1] > _vec[end - 1])
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
            for (size_t j = i; j < i + pairsize && j < _vec.size(); ++j)  
            {  
                chunk.push_back(_vec[j]);  
            }  
            
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

    std::cout << "TEMP" << std::endl;
    for (size_t i = 0; i < temp.size(); ++i)
    {
        for (size_t j = 0; j < temp[i].size(); ++j)
        {
            std::cout << temp[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Pairsize: " << pairsize << std::endl;
    std::cout << "MAIN:" << std::endl;
    for (size_t i = 0; i < main.size(); ++i)
    {
        for (size_t j = 0; j < main[i].size(); ++j)
        {
            std::cout << main[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "PEND:" << std::endl;
    for (size_t i = 0; i < pend.size(); ++i)
    {
        for (size_t j = 0; j < pend[i].size(); ++j)
        {
            std::cout << pend[i][j] << " ";
        }
        std::cout << std::endl;
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
                elementtoinsert = pend[_jbth - 2];
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
            size_t bound;
            int inserted = 0;
            if (boundElement == static_cast<size_t>(0))
                bound = main.size();
            else
                bound = boundElement;
            for (size_t j = 0; j < bound; ++j)
            {
                if (main[j][pairsize - 1] > elementtoinsert[pairsize - 1])
                {
                    if (j == 0)
                        main.insert(main.begin(), elementtoinsert);
                    else
                        main.insert(main.begin() + j, elementtoinsert);
                    inserted = 1;
                    if (pend.size() > 1)
                        pend.erase(pend.begin() + _jbth - 2);
                    else
                        pend.erase(pend.begin());
                    break;
                }
            }
            if (inserted == 0)
            {
                main.push_back(elementtoinsert);
                if (pend.size() > 1)
                    pend.erase(pend.begin() + _jbth - 2);
                else
                    pend.erase(pend.begin());
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


