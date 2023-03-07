#include <iostream>
#include <vector>
int main () {
    std::vector<int> v1;
    v1 ={1,3,3,5};
    v1.resize(2);
    for (int i=0; i<v1.size(); i++) {
           std::cout <<v1[i];
           
    }
 
}
