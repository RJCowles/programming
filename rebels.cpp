#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;
    for (int i = 1; i < 42; i++)
    {
        vec.push_back(i);
    }
    int j = 0;
    for (j; j < vec.size(); j++)
    {
        if (j % 3 == 0)
        {
            vec.at(j) = 0;
        }
        if (j == vec.size())
        {
            std::cout << j << std::endl;

            j = j % 3;
            for (int k = 0; k < vec.size(); k++)
            {
                if (vec.at(k) == 0)
                {
                    vec.erase(vec.begin() + k);
                }
            }
        }
    }
    for (int l = 0; l < vec.size(); l++)
    {
        std::cout << vec.at(l) << std::endl;
    }
}