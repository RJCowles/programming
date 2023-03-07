#include <iostream>
#include <cmath>

double checkABC() {
    double a;
    std::cin>>a;
    if (std::cin.fail()){
        throw std::runtime_error("Malformed user input");
    }
    else {
        return a;
    }

}

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
    try {
        a=checkABC();
        b=checkABC();
        c=checkABC();
        sinChanger = 1;
        if (a==0){
            throw std::runtime_error("a must not be zero");
        }
    }

    catch (std::runtime_error &excpt) {
        std::cout<<"An error occurred: "<< excpt.what() << std::endl;
        return 23;
    }

    

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