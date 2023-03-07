#include <iostream>
#include <vector>
#include <string>
// int main()
// {
//     std::vector<int> myVector;
//     myVector.push_back(2);
//     myVector.push_back(4);
//     for (int i = 0; i < myVector.size(); i++)
//     {
//         std::cout << "The number is : " << myVector.at(i) << std::endl;
//     }
// //     return 0;
// // }
// int return0()
// {
//     return -1;
// }

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec.at(i);
    }
}