#include <iostream>
#include <cmath>
#include <tuple>

int discriminant(double a, double b, double c)
{
    double discriminantValue;
    discriminantValue = pow(b, 2) + ((-4) * (a * c));
    return discriminantValue;
}
double getSolutions(double a, double b, double c, int sinChanger)
{
    double solutions;
    solutions = ((-b) + (sinChanger * sqrt(discriminant(a, b, c)))) / (2 * a);
    return (solutions);
}
int main()
{
    double a, b, c, solutions;
    int sinChanger;
    std::cout << "give me values  3" << std::endl;
    std::cin >> a >> b >> c;
    sinChanger = 1;

    if (discriminant(a, b, c) > 0)
    {
        std::cout << "there are 2 solutions " << discriminant(a, b, c) << " " << getSolutions(a, b, c, sinChanger);
        sinChanger = -1;
        std::cout << " and " << getSolutions(a, b, c, sinChanger);
    }
    else if (discriminant == 0)

    {
        std::cout << "only one solution as discriminant is 0 " << getSolutions(a, b, c, sinChanger);
    }
    else
    {
        std::cout << "there is no solution";
    }
}