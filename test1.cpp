#include <iostream>
#include <cmath>

int discriminant(double a, double b, double c)
{
    double discriminantValue;
    discriminantValue = pow(b, 2) + ((-4) * (a * c));
    return discriminantValue;
}
int solution1(double a, double b, double c)
{
    double solution1;
    solution1 = (((-b) + (sqrt(discriminant(a, b, c)))) / (2 * a));
    return solution1;
}
int solution2(double a, double b, double c) {
    double solution2;
    solution2 = (((-b) - (sqrt(discriminant(a, b, c)))) / (2 * a));
    return solution2;


}
int main()
{
    double solutionOne;
    double solutionTwo;
    double a;
    double b;
    double c;
    std::cout << "give me three numbers" << std::endl;
    std::cin >> a >> b >> c;
    if (discriminant(a, b, c) > 0)
    {
        std::cout << "there are 2 solutions the discriminant is " << discriminant(a,b,c) << std::endl;
        std::cout << " 2 solutions are " << solution1(a,b,c) << " and " << solution2(a,b,c) << std::endl;
    }
    else if (discriminant(a, b, c) == 0)
    {
        std::cout << " there is only one real solution, the discriminant is " << discriminant(a,b,c)<< std::endl;
        std::cout << "the solution is" << solution1;
    }
    else
    {
        std::cout << "there is no real solution, L as the discriminant is "<< discriminant(a,b,c) <<"which is a negative number"<< std::endl;
    }
}