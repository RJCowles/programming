
#include <iostream>
int main()
{

    int seqNumber;
    int counter = 0;
    std::cout << "Enter the first number of the sequence:" << std::endl;
    std::cin >> seqNumber;
    while (counter < 3)
    {
        std::cout << (seqNumber) << " ";
        if (seqNumber == 1)
        {
            counter++;
        }

        if (seqNumber % 2 == 0)
        {
            seqNumber = seqNumber / 2;
        }

        else
        {
            seqNumber = ((3 * seqNumber) + 1);
        }
    }
    std::cout << "...";
    return 0;
}
