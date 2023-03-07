#include <iostream>
#include <string>
#include <vector>
bool check_int(std::string string)
{
    for (int i = 0; i < string.length(); i++)
    {
        if (isdigit(string[i]) == false)
        {

            return false;
        }
    }
    return true;
}

bool in_bounds(int x, int y, int boardSize)
{
    if (x >= 0 && x < boardSize && y >= 0 && y < boardSize)
    {
        return true;
    }
    return false;
}
int main(int argc, char *argv[])
{
    std::string boardSize = argv[1];
    int boardSizeAsInt = stoi(boardSize);
    std::string startPos = argv[2];
    std::string endPos = argv[3];
    int x = startPos[0] - 97;
    int y = stoi(startPos.substr(1, 3)) - 1;
    int endPosX = endPos[0] - 97;
    int endPosY = stoi(endPos.substr(1, 3)) - 1;
    std::cout << x << std::endl;
    std::cout << y << std::endl;

    std::cout << endPosX << std::endl;
    std::cout << endPosY << std::endl;
    std::cout << boardSize << std::endl;
    std::cout << boardSizeAsInt + 1 << std::endl;
    if (!in_bounds(x, y, boardSizeAsInt) || !in_bounds(endPosX, endPosY, boardSizeAsInt))
    {
        std::cout << "out of bounds";
    }
}

// int a;
// int c;
// std::string boardSize;
// if (argc == 4)
// {
//     std::vector<std::string> stringOfChars;
//     boardSize = argv[1];
//     c = boardSize[0] - 97;
//     a = stoi(boardSize.substr(1, 2);

//     // b = stoi(boardSize.substr(1, boardSize.length() - 1));
//     // std::cout << a + 5;
//     std::cout << c << std::endl;
//     std::cout << a << std::endl;
//     int boardSizeAsInt = stoi(boardSize);
//     std::cout << boardSizeAsInt + 25;
// }
// // std::cout << argv[0] << std::endl;
// // std::cout << argv[1] << std::endl;
// // std::cout << argv[2] << std::endl;
// // std::cout << argv[3] << std::endl;
// // std::cout << "ha" << argc;
// int char_ascii = int(str[i]);