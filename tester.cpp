#include <iostream>
#include <vector>
#include <stdexcept>
int abcReader () {
    int a,b,c;
    std::cout<<"give me a,b,c values"<<std::endl;
    std::cin>>a,b,c;
    if (std::cin.good()==false) {
        throw std::runtime_error("invalid hoe");
    }
    while (std::cin>>a,b,c && std::cin.good())

return a,b,c;

}

int main () {
    try {
        abcReader();
/*      
        int a,b,c;
        std::cout<<"give me a,b,c values"<<std::endl;
        std::cin>>a,b,c;
        if (std::cin.good()) {
            std::cout<<"i love dick";
        }
*/
}
    catch(std::runtime_error &excpt) {
        std::cout<<excpt.what()<<"you filfy rat";
    }
return 0;
}