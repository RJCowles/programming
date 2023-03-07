#include <iostream>
#include <vector>

int main () {
    int n;
    std::cout<<"how many fibonacci numbers do you want"<<std::endl;
    std::cin>>n;
    n=n;
    std::vector<int> v1 = {0,1};
    int x;
    if (n==0){
        std::cout<<
    }
    for (int i=0; i<=n-2;i++) {
        x= v1[i]+v1[i+1];
        v1.push_back(x);
    }
    for (int j=0; j<v1.size(); j++) {
        std::cout<< v1[j]<<std::endl;

    }

        
}