//
// Created by sciphilib on 4/30/2022.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <sstream>

using namespace std;

int getRandomNumber(int a, int b)
{
    std::random_device random_device; // create object for seeding
    std::mt19937 engine{random_device()}; // create engine and seed it
    std::uniform_int_distribution<> dist(a, b); // create distribution for integers with [a, b] range
    return dist(engine); // finally get a pseudo-random integer number
}

int binarySearch(const std::vector<int> &arr, int number)
{
    int low = 0, mid;
    int high = arr.size() - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (number < arr[mid])
            high = mid - 1;
        else if (number > arr[mid])
            low = mid + 1;
        else
            return arr[mid]; // found
    }
    return -1; // if not found
}

int main()
{
    std::vector<int> arr{-92, -30, 20, -90, -72, -5, -7, -31, -41, 0, 27, -35, -24, 86, 73, 52, -63, -51, 98, -25, 76, -42, -95, -12, 78, -36, 87, -87, -23, 33, -66, 9, 82, -65, 81, -1, -71, -79, 75, -84, -26, -52, -54, 31, -94, -49, 67, 37, 62, -44, -59, 12, -62, 63, 66, -48, 6, 18, -2, -83, 55, 71, 64, 29, 69, 16, 84, 90, 14, 3, 79, -76, -93, -77, 70, -70, -73, 49, -85, -97, 95, 25, -50, 40, 94, 96, -57, -15, -29, 21, -96, -69, -61, -100, 38, -67, 42, 46, 47, 54};

    int number = 96; // existence value to find

    std::sort(arr.begin(), arr.end());      // binary search need sorted vector
    std::cout << binarySearch(arr, number) << '\n';
}
