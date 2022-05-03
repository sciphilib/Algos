//
// Created by sciphilib on 4/30/2022.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <sstream>

using namespace std;

bool binarySearch(const std::vector<int> &arr, int number)
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
            return true; // found
    }
    return false; // if not found
}

// Recursive version
bool binarySearchRec(const std::vector<int> &arr, int number, int low, int high)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (number < arr[mid])
            return binarySearchRec(arr, number, low, mid - 1);
        else if (number > arr[mid])
            return binarySearchRec(arr, number, mid + 1, high);
        else
            return true; // found
    }
    else
        return false;  // if not found
}

int main()
{
    std::vector<int> arr{-92, -30, 20, -90, -72, -5, -7, -31, -41, 0, 27, -35, -24, 86, 73, 52, -63, -51, 98, -25, 76, -42, -95, -12, 78, -36, 87, -87, -23, 33, -66, 9, 82, -65, 81, -1, -71, -79, 75, -84, -26, -52, -54, 31, -94, -49, 67, 37, 62, -44, -59, 12, -62, 63, 66, -48, 6, 18, -2, -83, 55, 71, 64, 29, 69, 16, 84, 90, 14, 3, 79, -76, -93, -77, 70, -70, -73, 49, -85, -97, 95, 25, -50, 40, 94, 96, -57, -15, -29, 21, -96, -69, -61, -100, 38, -67, 42, 46, 47, 54};

    int number = -30; // existence value to find
    std::sort(arr.begin(), arr.end());      // binary search need sorted vector

    std::cout << '\n';
    std::cout << binarySearch(arr, number) << '\n';
    std::cout << binarySearchRec(arr, number, 0, arr.size()-1) << '\n';
}
