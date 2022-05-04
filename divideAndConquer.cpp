//
// Created by sciphilib on 4/30/2022.
//

// Time Complexity: O(n) (for the Sum of n Elements problem)
// Space Complexity: O(n)

#include <iostream>
#include <random>


int getRandomNumber(int a, int b)
{
    std::random_device random_device; // create object for seeding
    std::mt19937 engine{random_device()}; // create engine and seed it
    std::uniform_int_distribution<> dist(a, b); // create distribution for integers with [a, b] range
    return dist(engine); // finally get a pseudo-random integer number
}

int dac(int *array, int start, int finish)
{
    int mid;
    if (start == finish)
        return array[start];
    else
    {
        mid = (start + finish) / 2;
        return dac(array, start, mid) + dac(array, mid+1, finish);
    }
}


int main()
{

    int size = 100;
    int array[size];

    for (auto &i:array) {
        i = getRandomNumber(0,10);
    }

    std::cout << dac(array, 0, size-1);
    return 0;
}