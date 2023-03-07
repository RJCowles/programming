#include <iostream>
#include <vector>

class vector
{
public:
    void PrintA()
    {
        a++;
        std::cout << a;
    }

private:
    int a = 0;
};
int main()
{
    vector a;
    a.PrintA();
    a.PrintA();
    a.PrintA();
    a.PrintA();
    a.PrintA();
}