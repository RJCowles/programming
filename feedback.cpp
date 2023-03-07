#include <iostream>
#include <stdexcept>


int main() {
    int i = 98;
    char c = 'A'-65 + i;
    std::cout<<c;
}