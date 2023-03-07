#include <iostream>
#include <vector>

void dedulicator (std::vector<int>& v1,std::vector<int>& v2) {
    int x,y;
    bool breaker;

        v2.push_back(v1[0]);

        for (int i = 0; i < v1.size(); i++)
        {
            breaker = false;
            x = v1.at(i);
            for (int j = 0; j < v2.size(); j++)
            {
                y = v2.at(j);
                if (x == y)
                {
                    breaker = true;
                    break;
                }
            }
            if (breaker == false)
            {
                v2.push_back(v1[i]);
            }
        }
    }



int main () {
    int inputValue;
    std::vector<int> vector1;
    std::vector<int> vector2;
    std::cout << "Enter the vector elements:" << std::endl;
    
    while (std::cin >> inputValue)
    {
        vector1.push_back(inputValue);
    }
    dedulicator(vector1,vector2);
    std::cout<<"The deduplicated vector is: ";
    std::cout<< "[";
    for (int k = 0; k<vector2.size();k++) {

        std::cout<<vector2[k];
        if (vector2.size()-1!=k) {
            std::cout<<",";


        }
    }
    std::cout<< "]";
}


