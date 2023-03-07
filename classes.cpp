#include <iostream>
#include <vector>
#include <cstdlib>
// random include
class cock
{
public:
    int cockGirth;
    int cockLength;
    std::string cockName;
    cock(int girth, int length, std::string name)
    {
        cockName = name;
        cockLength = length;
        cockGirth = girth;
    }
    int bangAHoe()
    {
        int whichHoe = rand() % 6 + 1;
        return whichHoe;
    }
    bool checkHoe(int whichHoe)
    {
        std::cout << "hoe number " << whichHoe << std::endl;
        if (whichHoe == 6)
        {
            std::cout << "menace to society, diamond ass hoe" << std::endl;
            return true;
        }
        else
        {
            std::cout << "gravel donkey";
            return false;
        }
    }
    void printStats()
    {
        std::cout << cockName << " the third" << std::endl;
        std::cout << cockLength << "m" << std::endl;
        std::cout << cockGirth << "mm" << std::endl;
    }
};

int main()
{
    cock robbiesCock(5, 25, "john jerome williams");
    robbiesCock.printStats();
    int whichHoe = robbiesCock.bangAHoe();
    while (!robbiesCock.checkHoe(whichHoe))
    {
        int whichHoe = robbiesCock.bangAHoe();
    }
}
