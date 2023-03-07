
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int main()
{
    std::vector<int> vector1(26, 0);
    // a string variable named str
    std::string str = "aaoo";
    int most_repeated = 0;
    char most_repeated_letter;
    int most_repeated_vowel=0;
    char most_repeated_vowel_letter;
    int most_repeated_consonant=0;
    char most_repeated_consonant_letter;


    for (int i = 0; i < str.length(); i++)
    {
        int num = int(str[i]);
        if (num >= 97 && num <= 122)
        {      
            vector1[num - 97]++;
            if ((num-97)==0 || (num-97)==4 || (num-97)==8 || (num-97)==14 || (num-97==20)){
                std::cout<<"vowel ";
                if (vector1[num-97]>most_repeated_vowel){
                    
                    most_repeated_vowel=vector1[num-97];
                    most_repeated_vowel_letter=num;
                    std::cout<<most_repeated_vowel_letter;

                }
            }else {
                if (vector1[num-97]>most_repeated_consonant) {

                    most_repeated_consonant=vector1[num-97];
                    most_repeated_consonant_letter=num;
                    std::cout<<"consonant ";

                }
            }
            
            if (vector1[num - 97] > most_repeated)
            {
                most_repeated = vector1[num - 97];

            }
        }
        else if (num >= 65 && num <= 90)
        {
            vector1[num - 65]++;
            if ((num-65)==0 || (num-65)==4 || (num-65)==8 || (num-65)==14 || (num-65==20)){
                
                if (vector1[num-65]>most_repeated_vowel){
                    
                    most_repeated_vowel=vector1[num-65];
                    most_repeated_vowel_letter=num;
                    std::cout<<most_repeated_vowel_letter;

                }
            }else {
                if (vector1[num-65]>most_repeated_consonant) {

                    most_repeated_consonant=vector1[num-65];
                    most_repeated_consonant_letter=num;
                    

                }
            }
            if (vector1[num - 65] > most_repeated)
            {
                most_repeated = vector1[num - 65];
            }
        }
    }
    for (int j = 0; j < vector1.size(); j++)
    {
        std::cout << vector1[j] << std::endl;
    }

    for (int k = 0; k < vector1.size(); k++)
    {
        if (vector1[k] == most_repeated)
        {
            most_repeated_letter = (k + 97);
        }
    }
    most_repeated_vowel_letter=tolower(most_repeated_vowel_letter);
    most_repeated_consonant_letter=tolower(most_repeated_consonant_letter);
    std::cout << most_repeated_letter << most_repeated << std::endl;
    std::cout<< most_repeated_vowel_letter<< most_repeated_vowel <<std::endl;
    std::cout<< most_repeated_consonant_letter<<most_repeated_consonant <<std::endl;
}

