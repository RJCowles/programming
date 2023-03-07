#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>
class MazeGeneration
{
public:
    std::stringstream ss;
    int counter = 1;
    int limitX;
    int limitY;
    std::string counterString;
    std::vector<std::vector<std::string>> maze;
    void createEmptyMaze();
    void searchPath();
    void shuffler(std::vector<int> &list);
    bool solveMaze(std::vector<std::vector<std::string>> &maze, int startX, int startY);
    std::vector<std::vector<std::string>> clearMaze(std::vector<std::vector<std::string>> maze);
    void breakWalls(std::vector<std::vector<std::string>> &maze, int startX, int startY, int newPosX, int newPosY, std::string counterString);

    MazeGeneration(int height, int width)
    {
        limitX = (2 * width) + 1;
        limitY = (2 * height) + 1;
        std::vector<std::vector<std::string>> maze1(limitX, std::vector<std::string>(limitY, "0"));
        maze = maze1;
        ss << counter;
        counterString = ss.str();
        maze.at(limitX - 2).at(limitY - 2) = counterString;
    }
    bool generatePath(std::vector<std::vector<std::string>> &maze, int startX, int startY, std::string counterString, int counter);
};
void MazeGeneration::shuffler(std::vector<int> &list)

{

    int n = list.size();

    for (int i = 0; i < n - 1; i++)
    {
        int j = i + rand() % (n - i);
        std::swap(list.at(i), list.at(j));
    }
}
void MazeGeneration::createEmptyMaze()
{
    for (int i = 0; i < limitX; i++)
    {
        for (int j = 0; j < limitY; j++)
        {
            if (i % 2 == 0 && j % 2 == 0)
            {
                maze.at(i).at(j) = "+";
            }
            else if (i % 2 == 1 && j % 2 == 0)
            {
                maze.at(i).at(j) = "|";
            }
            else if (i % 2 == 0 && j % 2 == 1)
            {
                maze.at(i).at(j) = "-";
            }
        }
    }
}
void MazeGeneration::breakWalls(std::vector<std::vector<std::string>> &maze, int startX, int startY, int newPosX, int newPosY, std::string counterString)
{
    if (newPosX > startX)
    {
        maze.at(newPosX - 1).at(newPosY) = counterString;
    }
    else if (newPosX < startX)
    {
        maze.at(newPosX + 1).at(newPosY) = counterString;
    }
    else if (newPosY > startY)
    {
        maze.at(newPosX).at(newPosY - 1) = counterString;
    }
    else if (newPosY < startY)
    {
        maze.at(newPosX).at(newPosY + 1) = counterString;
    }
}
void MazeGeneration::searchPath()
{
    for (int x = 1; x < limitX; x++)
    {
        for (int y = 1; y < limitY; y++)
        {
            if (maze.at(x).at(y) == "0")
            {
                counter++;
                ss = std::stringstream();
                ss << counter;
                std::string counterString = ss.str();
                maze.at(x).at(y) = counterString;
                generatePath(maze, x, y, counterString, counter);
            }
        }
    }
}
bool MazeGeneration::generatePath(std::vector<std::vector<std::string>> &maze, int startX, int startY, std::string counterString, int counter)
{
    std::vector<int> list = {0, 1, 2, 3};
    shuffler(list);
    int newPosX, newPosY;
    // start by generating a move
    std::vector<int> moveX = {2, -2, 0, 0};
    std::vector<int> moveY = {0, 0, 2, -2};
    // check about s rand
    for (int i = 0; i < list.size(); i++)
    {

        newPosX = startX + moveX.at(list.at(i));
        newPosY = startY + moveY.at(list.at(i));
        if (newPosX < limitX && newPosY < limitY && newPosX > 0 && newPosY > 0)
        {
            if (maze.at(newPosX).at(newPosY) != counterString)
            {
                if (maze.at(newPosX).at(newPosY) < counterString && maze.at(newPosX).at(newPosY) != "0")
                {
                    if (maze.at(newPosX).at(newPosY) == "1")
                    {
                        // breakWalls(maze, startX, startY, newPosX, newPosY, counterString);
                        maze.at(newPosX).at(newPosY) = "1000000000";
                        return true;
                    }
                    else
                    {
                        breakWalls(maze, startX, startY, newPosX, newPosY, counterString);
                        return true;
                    }
                }
                else if (maze.at(newPosX).at(newPosY) == "0")
                {

                    maze.at(newPosX).at(newPosY) = counterString;
                    breakWalls(maze, startX, startY, newPosX, newPosY, counterString);
                    generatePath(maze, newPosX, newPosY, counterString, counter);
                }
            }
        }
    }
    return false;
}
std::vector<std::vector<std::string>> MazeGeneration::clearMaze(std::vector<std::vector<std::string>> maze)
{
    std::vector<std::vector<std::string>> clearMaze;
    for (int x = 1; x < limitX; x++)
    {
        for (int y = 1; y < limitY; y++)
        {
            if (maze.at(x).at(y) != "+" && maze.at(x).at(y) != "-" && maze.at(x).at(y) != "|")
            {
                maze.at(x).at(y) = " ";
            }
        }
    }
    clearMaze = maze;
    return clearMaze;
}
class MazePrinting
{
public:
    std::vector<std::vector<std::string>> maze;
    int limitX;
    int limitY;
    MazePrinting(std::vector<std::vector<std::string>> matrix, int width, int length)
    {
        maze = matrix;
        limitX = width;
        limitY = length;
    }
    void printvariable()
    {
        std::cout << maze.size() << " <-- size" << std::endl;
    }

    void rintMaze()
    {
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

        for (int i = 0; i < limitX; i++)
        {
            for (int j = 0; j < limitY; j++)
            {
                if (maze.at(i).at(j) == "-")
                {
                    std::cout << maze.at(i).at(j);
                    std::cout << "--";
                }
                else if (maze.at(i).at(j) == " " && j % 2 == 0)
                {
                    std::cout << " ";
                }
                else if (maze.at(i).at(j) == " ")
                {
                    std::cout << " "
                              << " "
                              << " ";
                }
                else if (maze.at(i).at(j) == ".")
                {
                    std::cout << " " << maze.at(i).at(j) << " ";
                }
                else
                {
                    std::cout << maze.at(i).at(j);
                }
            }
            std::cout << std::endl;
        }
    }
};

bool MazeGeneration::solveMaze(std::vector<std::vector<std::string>> &maze, int startX, int startY)
{
    int newMoveX, newMoveY;

    if (startX == (limitX - 2) && startY == (limitY - 2))
    {
        maze.at(startX).at(startY) = ".";
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
            if (maze.at(newMoveX).at(newMoveY) == " ")
            {
                maze.at(startX).at(startY) = ".";
                if (solveMaze(maze, newMoveX, newMoveY))
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
int main(int argc, char *argv[])
{
    try
    {
        if (argc < 3)
        {
            throw std::runtime_error("too little inputs");
        }
        if (argc > 4)
        {
            throw std::runtime_error("too many inputs");
        }
        if (argc == 4)
        {
            std::string seed = argv[3];
            int seedAsInt = stoi(seed);
            std::srand(seedAsInt);
        }
        else
        {
            std::srand(std::time(0));
        }
        std::string width = argv[1];
        std::string height = argv[2];
        int widthAsInt, heightAsInt;
        widthAsInt = stoi(width);
        heightAsInt = stoi(height);

        MazeGeneration maze1 = MazeGeneration(heightAsInt, widthAsInt);
        maze1.createEmptyMaze();
        maze1.searchPath();
        std::vector<std::vector<std::string>> maze;
        maze = maze1.clearMaze(maze1.maze);
        maze1.solveMaze(maze, 1, 1);

        MazePrinting printMaze1(maze, maze1.limitX, maze1.limitY);
        printMaze1.rintMaze();
    }
    catch (std::runtime_error &excpt)
    {
    }
}