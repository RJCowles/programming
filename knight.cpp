#include <iostream>
#include <vector>
#include <string>

void printStrings(std::vector<char> charString, std::vector<int> intString)
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
bool check_correct_2_3_input(int x_value_in_char)
{
    if (x_value_in_char >= 97 && x_value_in_char <= 122)
    {
        return true;
    }
    return false;
}
bool in_bounds(int x, int y, int boardSize)
{
    if (x >= 0 && x < boardSize && y >= 0 && y < boardSize)
    {
        return true;
    }
    return false;
}
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
bool Move(int x, int y, std::vector<std::vector<int>> &matrix, int endpointX, int endpointY, int boardSize, std::vector<char> posChar, std::vector<int> posInt)
{
    posInt.push_back(y + 1);
    posChar.push_back(97 + x);
    bool functionEnder = false;
    matrix[x][y]++;
    // might need to add a stopper to the first if statement. to return something if we reached endpoint but didnt reach matrix full
    if (x == endpointX && y == endpointY)
    {
        printStrings(posChar, posInt);
        return true;
    }
    else
    {
        // generate first possible move and move there
        std::vector<int> xMove = {1, 2, 2, 1, -1, -2, -2, -1};
        std::vector<int> yMove = {2, 1, -1, -2, -2, -1, 1, 2};
        for (int i = 0; i < 8; i++)
        {
            int newPosX = x + xMove[i];
            int newPosY = y + yMove[i];
            if ((newPosX) < boardSize && (newPosX) >= 0 && (newPosY) < boardSize && (newPosY) >= 0)
            {
                // check how to do this with vec.at
                if (matrix[newPosX][newPosY] == 0)
                {

                    if (Move(newPosX, newPosY, matrix, endpointX, endpointY, boardSize, posChar, posInt))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    return false;
}
int main(int argc, char *argv[])
{
    // might come across problem when trying to input non integers
    try
    {
        if (argc == 4)
        {

            std::string boardSize = argv[1];
            if (!check_int(boardSize))
            {
                // can put this in function
                throw std::runtime_error("wrong first input");
            }
            int boardSizeAsInt = stoi(boardSize);
            if (boardSizeAsInt >= 27)
            {
                throw std::runtime_error("too large board size");
            }
            std::string startPos = argv[2];
            std::string endPos = argv[3];
            if (!check_correct_2_3_input(startPos[0]) || !check_correct_2_3_input(endPos[0]))
            {
                throw std::runtime_error("wrong input for spot 2 and 3");
            }
            int x = startPos[0] - 97;
            int y = stoi(startPos.substr(1, 3)) - 1;
            int endPosX = endPos[0] - 97;
            int endPosY = stoi(endPos.substr(1, 3)) - 1;
            if (!in_bounds(x, y, boardSizeAsInt) || !in_bounds(endPosX, endPosY, boardSizeAsInt))
            {
                throw(std::runtime_error("not in bounds"));
            }

            // creating an 8x8 vector as test example
            std::vector<std::vector<int>> vector(boardSizeAsInt, std::vector<int>(boardSizeAsInt, 0));
            std::vector<char> posChar;
            std::vector<int> posInt;
            //                x, y, matrix, endpoitns, size of matrix,
            if (!Move(x, y, vector, endPosX, endPosY, boardSizeAsInt, posChar, posInt))
            {
                std::cout << "could not find a knight's tour";
            }

            // std::cout << std::endl;
            // printStrings(posChar, posInt);
        }
        else
        {
            throw std::runtime_error("too many letters");
        }
    }
    catch (std::runtime_error &excpt)
    {
        std::cout << "invalid parameter list" << std::endl;
    }
    return 0;
}

// need to make a string which outputs a list of moves
// moves =a1,a2,a3
// read input
// argc == 4 else invalid paramenter list
// boardsize=argv[1]
// change all the idx into .at
// error catching
// at at at