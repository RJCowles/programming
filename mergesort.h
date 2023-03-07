#include <iostream>
#include <vector>
using namespace std;

template <typename Type>
void merge(std::vector<Type> &numbers, int i, int j, int k)
{
    int mergedSize; // Size of merged partition
    int mergePos;   // Position to insert merged number
    int leftPos;    // Position of elements in left partition
    int rightPos;   // Position of elements in right partition
                    //

    mergePos = 0;
    mergedSize = k - i + 1;
    leftPos = i; // Initialize left partition position
    rightPos = j + 1;
    std::vector<Type> mergedNumbers(mergedSize); // Initialize right partition position
                                                 // Dynamically allocates temporary array
                                                 // for merged numbers

    // Add smallest element from left or right partition to merged numbers
    while (leftPos <= j && rightPos <= k)
    {
        if (numbers.at(leftPos) < numbers.at(rightPos))
        {
            mergedNumbers.at(mergePos) = numbers.at(leftPos);
            ++leftPos;
        }
        else
        {
            mergedNumbers.at(mergePos) = numbers.at(rightPos);
            ++rightPos;
        }
        ++mergePos;
    }

    // If left partition is not empty, add remaining elements to merged numbers
    while (leftPos <= j)
    {
        mergedNumbers.at(mergePos) = numbers.at(leftPos);
        ++leftPos;
        ++mergePos;
    }

    // If right partition is not empty, add remaining elements to merged numbers
    while (rightPos <= k)
    {
        mergedNumbers.at(mergePos) = numbers.at(rightPos);
        ++rightPos;
        ++mergePos;
    }

    // Copy merge number back to numbers
    for (mergePos = 0; mergePos < mergedSize; ++mergePos)
    {
        numbers.at(i + mergePos) = mergedNumbers.at(mergePos);
    }
    mergedNumbers.clear();
}
template <typename Type>
void mergeSort(std::vector<Type> &numbers, int i, int k)
{
    int j;

    if (i < k)
    {
        j = (i + k) / 2; // Find the midpoint in the partition

        // Recursively sort left and right partitions
        mergeSort(numbers, i, j);
        mergeSort(numbers, j + 1, k);

        // Merge left and right partition in sorted order
        merge(numbers, i, j, k);
    }
}