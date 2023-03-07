#include <iostream>
#include <vector>
class Stack
{
public:
    std::vector<int> vec = {};
    bool isEmpty()
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
    int pop()
    {
        // if (isEmpty() == false)
        // {
        int PopValue = vec.at(vec.size() - 1);
        vec.pop_back();
        return PopValue;
        // }
        // else
        // {
        // std::cout << "empty";
        // }
    }
    void push(int i)
    {
        vec.push_back(i);
    }
    int top() const
    {
        return vec.at(vec.size() - 1);
    }
    std::string toString() const
    {
        // std::tostring
        std::string listString = "[";
        char a;
        for (int i = 0; i < vec.size(); i++)
        {

            a = vec.at(i) + 48;
            listString.push_back(a);
            if (i < vec.size() - 1)
            {
                listString.push_back(',');
            }
        }
        listString.push_back(']');
        return listString;
    }

    // int top() const
};

int main()
{
    int i;
    Stack stack1;
    // std::cout << stack1.pop() << std::endl;
    // std::cout << stack1.pop() << std::endl;
    std::cin >> i;
    stack1.push(i);
    // std::cout << stack1.pop() << std::endl;
    // std::cout << stack1.top();
    std::cout << stack1.toString();
}