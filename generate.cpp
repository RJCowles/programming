#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

void shuffler(std::vector<int> &list)
{
    int n = list.size();

    for (int i = 0; i < n - 1; i++)
    {
        // generate a random number `j` such that `i <= j < n` and
        // swap the element present at index `j` with the element
        // present at current index `i`
        int j = i + rand() % (n - i);
        std::swap(list[i], list[j]);
    }
}
void generatePath(std::vector<std::vector<std::string>> &maze, int limitX, int limitY, int counter, int startX, int startY)
{
    int newPosX;
    int newPosY;
    std::vector vec = {0, 1, 2, 3};
    shuffler(vec);
    // definately a more elegant solution than this
    // maybe turn this into array
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == 0)
        {
            newPosX = startX + 2;
            newPosY = startY;
        }
        else if (vec[i] == 1)
        {
            newPosX = startX - 2;
            newPosY = startY;
        }
        else if (vec[i] == 2)
        {
            newPosY = startY + 2;
            newPosX = startX;
        }
        else if (vec[i] == 3)
        {
            newPosY = startY - 2;
            newPosX = startX;
        }
        // if it is inbounds
        if (newPosX != limitX && newPosY != limitY && newPosX != 0 && newPosY != 0)
        {
            // if it is not going over its own ath
            if (maze[newPosX][newPosY] != counterString)
            {

                if (maze[newPosX][newPosY] < counterString)
                {
                    // done found ath
                    break;
                }
                else if (maze[newPosX][newPosY] == "0")
                {
                    maze[newPosX][newPosY] = counterString;
                    if (newPosX > startX)
                    {
                        maze[newPosX - 1][newPosY] = counterString;
                    }
                    else if (newPosX < startX)
                    {
                        maze[newPosX + 1][newPosY] = counterString;
                    }
                    else if (newPosY > startY)
                    {
                        maze[newPosX][newPosY - 1] = counterString;
                    }
                    else if (newPosY > startY)
                    {
                        maze[newPosX][newPosY + 1] = counterString;
                    }
                    generatePath(maze, limitX, limitY, counter, newPosX, newPosY);
                    break;
                }
            }
        }
    }
}
int main()
{
    int x = 2;
    int y = 2;
    std::vector<int> list = {0, 1, 2, 3};
    shuffler(list);
    for (int i = 0; i < list.size(); i++)
    {
        std::cout << list[i] << std::endl;
        makeMove(x, y, list[i]);
        std::cout << x << " " << y << std::endl;
    }
}
// i am going to void the generate ath function, then just reference the matrix