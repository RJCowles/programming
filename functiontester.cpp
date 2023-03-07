#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <climits>
int checkABC () {
    int x=0;
    double a,b,c;
    while (std::cin>>a,b,c && x<=3){
        
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(INT_MAX,'\n');
            throw std::runtime_error("bad input");
            x++;
            std::cout<<"x+1";
        }
        else{
            std::cout<<"x+1e";
            x++;
        }
    }
    std::cout<<"correct input";
    std::cout<<a<<b<<c;
    return a,b,c;
}
int main () {
    int a,b,c;
    try 
    {
        std::cout<<"give me three numbers a,b,c "<<std::endl;
        std::cout<< checkABC(); 
        
    }
    catch (std::runtime_error &excpt) {
        std::cout<<excpt.what()<<" i caught the error ";
    }

    return 0;
}