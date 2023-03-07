#include <iostream>
int main () {
    char operatorOne;
    int x=0;
    double valueOne;
    double valueTwo;
    while (x==0){
        std::cout << "Enter the expression: "<< std::endl;
        std::cin >> operatorOne;
        std::cin >> valueOne; 
        std::cin >> valueTwo;


        switch(operatorOne) {

            case '+': 
            std::cout << valueOne << " " << operatorOne << " " << valueTwo << " = ";
            std::cout << valueOne+valueTwo<<std::endl;
            break;

            case '-':
            std::cout << valueOne << " " << operatorOne << " " << valueTwo << " = ";
            std::cout << valueOne-valueTwo<< std::endl;
            break;

            case '*':
            std::cout << valueOne << " " << operatorOne << " " << valueTwo << " = ";
            std::cout << valueOne*valueTwo<< std::endl;
            break;

           case '/':
           std::cout << valueOne << " " << operatorOne << " " << valueTwo << " = ";
           std::cout << valueOne/valueTwo<< std::endl;
           break;

           case 'q': x++;
           break;

           default: std::cout <<"My calculator isnt good enough to take that "<< std::endl;

    }
    }
    return 0;
    }