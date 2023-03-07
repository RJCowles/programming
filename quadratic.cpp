#include <iostream>
#include <cmath>

double getDiscriminant(double a, double b, double c)
{
    double discriminantValue;
    discriminantValue = pow(b, 2) + (-4 * a * c);
    return discriminantValue;
}
double getSolutions(double a, double b, double c, int sinChanger)
{
    double solutions;
    solutions = (-b + (sinChanger * sqrt(getDiscriminant(a, b, c)))) / (2 * a);

    return (solutions);
}
int main()
{
    double a, b, c;
    int sinChanger;
    std::cout << "Please enter the values of a, b, and c: " << std::endl;
    std::cin >> a >> b >> c;
    sinChanger = 1;


    if (getDiscriminant(a, b, c) > 0)
    {
        std::cout << "There are 2 solutions." << std::endl;
        std::cout << "The solutions are: " << getSolutions(a, b, c, sinChanger);
        sinChanger = -1;
        std::cout << " and " << getSolutions(a, b, c, sinChanger);
    }
    else if (getDiscriminant(a, b, c) == 0)

    {
        std::cout << "There is 1 solution. " << std::endl;
        std::cout << "The solution is: " << getSolutions(a, b, c, sinChanger);
    }
    else
    {
        std::cout << "There is no solution.";
    }
    return 0;
}