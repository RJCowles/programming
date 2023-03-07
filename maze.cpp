#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>

void printMatrix(std::vector<std::vector<int>> matrix, int mazeLength, int mazeWidth)
{
    for (int i = 0; i < mazeWidth; i++)
    {
        for (int j = 0; j < mazeLength; j++)
        {
            std::cout << matrix.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void printStrings(std::vector<int> charString, std::vector<int> intString)
{
    for (int i = 0; i < charString.size(); i++)
    {
        std::cout << charString[i] << intString[i];
        if (i != charString.size() - 1)
        {
            std::cout << " ";
        }
    }
}
bool inBounds(int x, int y, int length, int width)
{
    if (x >= 0 && x < width && y >= 0 && y < length)
    {
        return true;
    }
    return false;
}
// class cell
// {
// public:
//     bool wallN = true;
//     bool wallE = true;
//     bool wallS = true;
//     bool wallE = true;
//     cell()
//     {
//     }
//     // make a variable that determines which direction it is
//     //
//     void breakWall(nextMoveX, nextMoveY)
//     {
//     }

//     // cell has 4 walls
// };
class MazeGen
{
public:
    std::vector<std::vector<int>> mazeMatrix;
    int mazeLength;
    int mazeWidth;
    int stePcounter = 1;
    std::vector<int> posX;
    std::vector<int> posY;
    std::vector<char> directionTook;
    char direction;
    // this is for when you develo P new Paths, after finding the first solution you increase the stePcounter.
    //  as we want to build walls around the ones with new Paths
    MazeGen(int length, int width, std::vector<std::vector<int>> matrix)
    {
        mazeMatrix = matrix;
        mazeLength = length;
        mazeWidth = width;
    }
    int randomMoveValue;
    std::vector<int> movesX = {1, 0, -1, 0};
    std::vector<int> movesY = {0, 1, 0, -1};
    bool makeMaze(int startX, int startY, int endX, int endY, std::vector<int> posX, std::vector<int> posY, std::vector<char> directionTook)
    {
        // ut matrix in arameter list as otherwise we cant take out moves that were bad
        posY.push_back(startY);
        std::cout << posY.at(posY.size() - 1);
        posX.push_back(startX);

        std::cout << posX.at(posX.size() - 1);
        std::cout << std::endl;
        directionTook.push_back(direction);
        mazeMatrix.at(startX).at(startY)++;

        if (startX == endX && startY == endY)
        {
            // printStrings(posChar, posInt);
            return true;
        }
        else
        {
            std::vector<int> moveX = {1, 0, -1, 0};
            std::vector<int> moveY = {0, 1, 0, -1};
            std::vector<char> listOfDirections = {'E', 'N', 'W', 'S'};
            for (int i = 0; i < 10; i++)
            {

                int randomMoveValue = rand() % 3;
                std::cout << randomMoveValue << "*" << std::endl;
                char direction = listOfDirections[randomMoveValue];
                int newPosX = startX + moveX.at(randomMoveValue);
                int newPosY = startY + moveY.at(randomMoveValue);
                if (inBounds(newPosX, newPosY, mazeLength, mazeWidth))
                {

                    if (mazeMatrix[newPosX][newPosY] != 1)
                    {
                        // wanted to add a vector of directions took
                        if (makeMaze(newPosX, newPosY, endX, endY, posX, posY, directionTook))
                        {
                            printMatrix(mazeMatrix, 4, 4);
                            return true;
                        }
                    }
                }
            }
            return false;
            // somehow run through random values without seeing a random value twice
        }
    }
};

int main()
{
    std::vector<int> posX;
    std::vector<int> posY;
    std::vector<char> directionTook;
    // confused what to add in as parameter
    int length;
    int width;
    std::vector<std::vector<int>> matrix(4, std::vector<int>(4, 0));

    MazeGen maze1(4, 4, matrix);
    maze1.makeMaze(0, 0, 3, 3, posX, posY, directionTook);
}