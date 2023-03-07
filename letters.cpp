#include <iostream>
#include <vector>

template <typename t>
t returnlargest(t value1, t value2, std::string string)
{
    if (value1 > value2)
    {
        std::cout << string;
        return value1;
    }
    else
    {
        std::cout << string;
        return value2;
    }
}
int main()
{
    // std::cout << returnlargest(5.1, 4.9, "im gay");

    int a = 5;
    int b = 11;
    double c = b / a;
    std::cout << c;
}