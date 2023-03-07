#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
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
};
int main()
{
    MazeGeneration maze1(5, 4);
    std::vector<std::vector<std::string>> myMaze;
    myMaze = maze1.maze;
    myMaze.at(maze1.limitX - 2).at(maze1.limitY - 2) = "1";
    for (int i = 0; i < maze1.limitX; i++)
    {
        for (int j = 0; j < maze1.limitY; j++)
        {
            std::cout << myMaze.at(i).at(j);
        }
        std::cout << std::endl;
    }
}