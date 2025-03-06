/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:36:09 by omartela          #+#    #+#             */
/*   Updated: 2025/03/05 12:36:10 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>
#include <Array.tpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
		// Should leak if destructor does not delete the array (free the array)
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
		// test index out of range
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
		// test index out of range
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

    Array<int> empty_array;
    if (empty_array.size() != 0) 
    {
        std::cerr << "Empty array constructor failed" << std::endl;
        return 1;
    }


    Array<int> single_element(1);
    if (single_element.size() != 1) {
        std::cerr << "Size function failed for single-element array" << std::endl;
        return 1;
    }

    Array<int> small_array(2);
    if (small_array.size() != 2) {
        std::cerr << "Size function failed for small array" << std::endl;
        return 1;
    }

    Array<double> double_array(5);
    double_array[0] = 3.14;  // Test for doubles

    std::cout << double_array[0] << std::endl;

    Array<std::string> string_array(2);
    string_array[0] = "Hello";
    string_array[1] = "World";

    std::cout << string_array[0] << std::endl;
    std::cout << string_array[1] << std::endl;

    Array<int> zero_size_array(0);
    if (zero_size_array.size() != 0) 
    {
        std::cerr << "Zero size array failed" << std::endl;
        return 1;
    }

    return 0;
}
