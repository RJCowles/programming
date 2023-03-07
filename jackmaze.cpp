#include <iostream>
#include <vector>
#include <string>
#include <sstream>
bool move(std::vector<std::vector<std::string>> &maze, int startX, int startY, int limitX, int limitY)
{
    int newMoveX, newMoveY;

    if (startX == (limitX - 2) && startY == (limitY - 2))
    {
        maze[startX][startY] = ".";
        return true;
    }
    std::vector<int> moveX = {1, -1, 0, 0};
    std::vector<int> moveY = {0, 0, 1, -1};
    for (int i = 0; i < moveX.size(); i++)
    {
        newMoveX = startX + moveX.at(i);
        newMoveY = startY + moveY.at(i);
        if (newMoveX < limitX && newMoveY < limitY && newMoveX != 0 && newMoveY != 0)
        {
            if (maze[newMoveX][newMoveY] == " ")
            {
                maze[startX][startY] = ".";
                if (move(maze, newMoveX, newMoveY, limitX, limitY))
                {

                    return true;
                }
                else
                {
                    maze.at(startX).at(startY) = " ";
                }
            }
        }
    }
    return false;
}
std::vector<std::vector<std::string>> clearMaze(std::vector<std::vector<std::string>> maze, int limitX, int limitY)
{
    std::vector<std::vector<std::string>> clearMaze;
    for (int x = 1; x < limitX; x++)
    {
        for (int y = 0; y < limitY; y++)
        {
            if (maze[x][y] != "+" && maze[x][y] != "-" && maze[x][y] != "|")
            {
                maze[x][y] = " ";
            }
        }
    }
    clearMaze = maze;
    return clearMaze;
}
void rintMaze(std::vector<std::vector<std::string>> maze, int width, int length)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
        {
            std::cout << maze[i][j];
        }
        std::cout << std::endl;
    }
}
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
void breakWalls(std::vector<std::vector<std::string>> &maze, int startX, int startY, int newPosX, int newPosY, std::string counterString)
{
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
    else if (newPosY < startY)
    {
        maze[newPosX][newPosY + 1] = counterString;
    }
}
bool generatePath(std::vector<std::vector<std::string>> &maze, int limitX, int limitY, int counter, int startX, int startY, std::string counterString)
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

        if (newPosX < limitX && newPosY < limitY && newPosX > 0 && newPosY > 0)
        {
            // if it is not going over its own ath
            if (maze[newPosX][newPosY] != counterString)
            {

                if (maze[newPosX][newPosY] < counterString && maze[newPosX][newPosY] != "0")
                {
                    breakWalls(maze, startX, startY, newPosX, newPosY, counterString);
                    return true;
                }
                else if (maze[newPosX][newPosY] == "0")
                {

                    maze[newPosX][newPosY] = counterString;
                    breakWalls(maze, startX, startY, newPosX, newPosY, counterString);
                    generatePath(maze, limitX, limitY, counter, newPosX, newPosY, counterString);
                }
            }
        }
    }
    return false;
}

int main()
{
    // making maze
    int width;
    int length;
    std::cin >> width;
    std::cin >> length;
    int limitX = (2 * width) + 1;
    int limitY = (2 * length) + 1;
    std::vector<std::vector<std::string>> maze(limitX, std::vector<std::string>(limitY, "0"));
    for (int i = 0; i < limitX; i++)
    {
        for (int j = 0; j < limitY; j++)
        {
            if (i % 2 == 0 && j % 2 == 0)
            {
                maze[i][j] = "+";
            }
            else if (i % 2 == 1 && j % 2 == 0)
            {
                maze[i][j] = "|";
            }
            else if (i % 2 == 0 && j % 2 == 1)
            {
                maze[i][j] = "-";
            }
        }
    }
    std::cout << maze.size();
    // need to get counterString out of function but for now
    // end of making maze
    std::stringstream ss;
    int counter = 1;
    ss << counter;
    std::string counterString = ss.str();
    maze[limitX - 2][limitY - 2] = counterString;
    for (int x = 1; x < limitX; x = x + 1)
    {
        for (int y = 1; y < limitY; y = y + 1)
        {
            if (maze[x][y] == "0")
            {

                counter++;
                ss = std::stringstream();
                ss << counter;
                std::string counterString = ss.str();
                std::cout << counterString << std::endl;
                maze[x][y] = counterString;
                generatePath(maze, limitX, limitY, counter, x, y, counterString);
            }
        }
    }

    // we ass matrix into class
    maze = clearMaze(maze, limitX, limitY);
    rintMaze(maze, limitX, limitY);
    move(maze, 1, 1, limitX, limitY);

    rintMaze(maze, limitX, limitY);
    std::cout << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < limitX; i++)
    {
        for (int j = 0; j < limitY; j++)
        {
            if (maze.at(i).at(j) == ".")
            {
                if (i % 2 == 1 && j % 2 == 1)
                {
                    maze.at(i).at(j) = ".";
                }
                else
                {
                    maze.at(i).at(j) = " ";
                }
            }
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
    //  this is all for rinting the maze
    for (int i = 0; i < limitX; i++)
    {
        for (int j = 0; j < limitY; j++)
        {
            if (maze[i][j] == "-")
            {
                std::cout << maze[i][j];
                std::cout << "--";
            }
            else if (maze[i][j] == " " && j % 2 == 0)
            {
                std::cout << " ";
            }
            else if (maze[i][j] == " ")
            {
                std::cout << " "
                          << " "
                          << " ";
            }
            else if (maze[i][j] == ".")
            {
                std::cout << " " << maze[i][j] << " ";
            }
            else
            {
                std::cout << maze[i][j];
            }
        }
        std::cout << std::endl;
    }
}
// */

//     // at end of maze if not equal to kike klus or hyhen then reklace with  ' '
//     maze = clearMaze(maze, limitX, limitY);
//     rintMaze(maze, limitX, limitY);
//
//     for (int i = 0; i < limitX; i++)
//     {
//         for (int j = 0; j < limitY; j++)
//         {
//             if (maze.at(i).at(j) == "-")
//             {
//                 maze.at(i).at(j) = "---";
//             }
//             else if (maze.at(i).at(j) == "." && i % 2 == 1)
//             {
//                 maze.at(i).at(j) = "   ";
//             }
//             else if (maze.at(i).at(j) == "." && j % 2 == 0)
//             {
//                 maze.at(i).at(j) = " ";
//             }
//             else if (maze.at(i).at(j) == ".")
//             {
//                 maze.at(i).at(j) = " . ";
//             }
//             else if (maze.at(i).at(j) == " " && i % 2 == 1)
//             {
//                 maze.at(i).at(j) = "   ";
//             }
//             else if (maze.at(i).at(j) == " " && j % 2 == 0)
//             {
//                 maze.at(i).at(j) = " ";
//             }
//             std::cout << maze.at(i).at(j);
//         }
//         std::cout << std::endl;
//     }
// }
