/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:44:30 by omartela          #+#    #+#             */
/*   Updated: 2025/03/05 11:44:31 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "../inc/iter.hpp"

void printInt(int i) 
{
    std::cout << i << std::endl;
}

void addOne(int &i) 
{
    i++;
}

void addTwo(int &i) 
{
    i += 2;
}

void addThree(int &i) 
{
    i += 3;
}

void decrement(int &i) 
{
    i--;
}

void decrementTwo(int &i) 
{
    i -= 2;
}

void decrementThree(int &i) 
{
    i -= 3;
}

void printString(std::string str) 
{
    std::cout << str << std::endl;
}

void addExclamation(std::string &str) 
{
    str += "!";
}

void addQuestionMark(std::string &str) 
{
    str += "?";
}

void addDot(std::string &str) 
{
    str += ".";
}

void addComma(std::string &str) 
{
    str += ",";
}

void printChar(char c) 
{
    std::cout << c << std::endl;
}

void toUpperCase(char &c) 
{
    if (c >= 'a' && c <= 'z') 
    {
        c = c - ('a' - 'A');
    }
}

void printFloat(float f) 
{
    std::cout << f << std::endl;
}

void addOneFloat(float &f) 
{
    f += 1.0f;
}

struct Point 
{
    int x, y;
};

void printPoint(const Point &p) 
{
    std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
}

void moveRight(Point &p) 
{
    p.x += 1;
}

int main() 
{
    int array[] = {1, 2, 3, 4, 5};
    std::cout << "Before:" << std::endl;
    iter(array, 5, printInt);
    iter(array, 5, addOne);
    std::cout << "After adding one:" << std::endl;
    iter(array, 5, printInt);
    iter(array, 5, addTwo);
    std::cout << "After adding two:" << std::endl;
    iter(array, 5, printInt);
    iter(array, 5, addThree);
    std::cout << "After adding three:" << std::endl;
    iter(array, 5, printInt);
    iter(array, 5, decrement);
    std::cout << "After decrementing one:" << std::endl;
    iter(array, 5, printInt);
    iter(array, 5, decrementTwo);
    std::cout << "After decrementing two:" << std::endl;
    iter(array, 5, printInt);
    iter(array, 5, decrementThree);
    std::cout << "After decrementing three:" << std::endl;
    iter(array, 5, printInt);


    std::string str_array[] = {"one", "two", "three", "four", "five"};
    std::cout << "Before:" << std::endl;
    iter(str_array, 5, printString);
    iter(str_array, 5, addExclamation);
    std::cout << "After adding exclamation mark:" << std::endl;
    iter(str_array, 5, printString);
    iter(str_array, 5, addQuestionMark);
    std::cout << "After adding question mark:" << std::endl;
    iter(str_array, 5, printString);
    iter(str_array, 5, addDot);
    std::cout << "After adding dot:" << std::endl;
    iter(str_array, 5, printString);
    iter(str_array, 5, addComma);
    std::cout << "After adding comma:" << std::endl;
    iter(str_array, 5, printString);

    Point pointArray[] = {{1, 2}, {3, 4}, {5, 6}};
    std::cout << "Before:" << std::endl;
    iter(pointArray, 3, printPoint);
    iter(pointArray, 3, moveRight);
    std::cout << "After moving right:" << std::endl;
    iter(pointArray, 3, printPoint);

    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    std::cout << "Before:" << std::endl;
    iter(floatArray, 5, printFloat);
    iter(floatArray, 5, addOneFloat);
    std::cout << "After adding one:" << std::endl;
    iter(floatArray, 5, printFloat);

    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    std::cout << "Before:" << std::endl;
    iter(charArray, 5, printChar);
    iter(charArray, 5, toUpperCase);
    std::cout << "After converting to upper case:" << std::endl;
    iter(charArray, 5, printChar);






    return 0;

}
