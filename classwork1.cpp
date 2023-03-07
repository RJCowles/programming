#include <iostream>
#include <vector>
int main () {
    std::vector<int> v1;
    v1 = {1,3,3,5};
    v1.push_back(10);
    std::cout<<v1[0];
    std::cout<<v1[1];
    std::cout<<v1[2];
    std::cout<<v1[3];
    std::cout<<v1[4];
    create a string which pushes back the value which is found duplicate, problem is also the values which arent duplicates
}