#include <iostream>
#include <cmath>
#include <cstdlib>

// void randomArray () {

int main()
{
    int randomValue;
    int array[20];
    for (int i = 0; i < 20; i++)
    {
        randomValue = rand() % 6 + 1;
        array[i] = randomValue;
    }
    std::cout << array;
}
