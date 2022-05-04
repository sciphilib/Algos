//
// Created by sciphilib on 5/4/2022.
//

// Time Complexity: O(nlogn)
// Space Complexity: O(n)

#include <algorithm>
#include <iostream>

void quicksort(int *arr, int left, int right)
{
    int i = left, j = right, mid = (left + right) / 2;
    int pivot = arr[mid];
    while (i <= j)
    {
        while (arr[i] < pivot)
            ++i;
        while (arr[j] > pivot)
            --j;
        if (i <= j)
        {
            std::swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }
    if (left < j)
        quicksort(arr, left, j);
    if (right > i)
        quicksort(arr, i, right);
}

int main()
{
    const int n = 100;
    int arr[n] = {-92, -30, 20, -90, -72, -5, -7, -31, -41, 0, 27, -35, -24, 86, 73, 52, -63, -51, 98, -25, 76, -42, -95, -12, 78, -36, 87, -87, -23, 33, -66, 9, 82, -65, 81, -1, -71, -79, 75, -84, -26, -52, -54, 31, -94, -49, 67, 37, 62, -44, -59, 12, -62, 63, 66, -48, 6, 18, -2, -83, 55, 71, 64, 29, 69, 16, 84, 90, 14, 3, 79, -76, -93, -77, 70, -70, -73, 49, -85, -97, 95, 25, -50, 40, 94, 96, -57, -15, -29, 21, -96, -69, -61, -100, 38, -67, 42, 46, 47, 54};
    quicksort(arr, 0, n -1);
    for (const auto &i:arr) {
        std::cout << i << ' ';
    }

    return 0;
}