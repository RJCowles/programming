#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

class cell
{
public:
    cell()
    {
    }
    // properties of a cell
    //  4 active sides
    bool North = true;
    bool East = true;
    bool South = true;
    bool West = true;
    // method to remove walls
    void Breakwall(bool wall)
    {
        wall = false;
    }
};

int main()
{
    cell cell1;
    std::vector<cell> vectorOfCells;
    // vectorOfCells.push_back(cell1);
    // vectorOfCells[0].Breakwall(cell1.North);
    // if (vectorOfCells[0]){
    //     std::cout<<"we cahnged the matrix";
    // }
    vectorOfCells.push_back(cell1);
    vectorOfCells[0].Breakwall(North);
    std::cout << vectorOfCells[0].North;
}
