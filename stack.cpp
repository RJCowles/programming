#include <iostream>
#include <limits>
#include <vector>
#include <sstream>
class Stack
{
public:
    Stack();
    int popValue;
    std::string listString;
    std::vector<int> vec;
    bool isEmpty() const;
    int top() const;
    int pop();
    void push(int i);
    std::string toString() const;

private:
    std::vector<int> elements;
};
Stack::Stack()
{
}
bool Stack::isEmpty() const
{
    if (vec.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int Stack::top() const
{
    if (isEmpty())
    {
        throw std::runtime_error("stack is empty");
    }
    return vec.at(vec.size() - 1);
}
void Stack::push(int i)
{

    vec.push_back(i);
}
int Stack::pop()
{
    if (isEmpty())
    {
        throw std::runtime_error("stack is empty");
    }
    popValue = vec.at(vec.size() - 1);
    vec.pop_back();
    return popValue;
}
std::string Stack::toString() const
{
    std::stringstream ss;
    ss << "[";
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        ss << vec.at(i);
        if (i != 0)
        {
            ss << ",";
        }
    }
    ss << "]";
    std::string listString = ss.str();
    return listString;
}

int main()
{

    Stack stack;

    while (true)
    {
        try
        {
            std::cout << "stack> ";

            std::string command;
            std::cin >> command;

            if ((command.compare("end") == 0) || std::cin.eof())
            {
                break;
            }
            else if (command.compare("top") == 0)
            {
                std::cout << stack.top() << std::endl;
            }
            else if (command.compare("pop") == 0)
            {
                std::cout << stack.pop() << std::endl;
            }
            else if (command == "push")
            {
                if (std::cin.eof())
                    break;
                int i;
                std::cin >> i;
                bool failed = std::cin.fail();
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (failed)
                {
                    throw std::runtime_error("not a number");
                }
                stack.push(i);
            }
            else if (command.compare("list") == 0)
            {
                std::cout << stack.toString() << std::endl;
            }
            else
            {
                throw std::runtime_error("invalid command");
            }
        }
        catch (std::runtime_error &e)
        {
            std::cout << "error: " << e.what() << std::endl;
        }
    }
}