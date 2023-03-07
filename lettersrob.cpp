
/*#include <iostream>
#include <string>

int main () {
    string a="A";
    int a_int=stoi(a);
    std::cout<<a_int;
return 0;
}
*/
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int main()
{
    std::vector<int> vector1(26, 0);
    // a string variable named str
    std::string str = "aaaaaa";
    int most_repeated = 0;
    char most_repeated_letter;
    int sum_of_consonants;
    int ;
    // print to the console

    // convert the string str variable to have an int value

    // most_repeated = 0
    // most_repeate_idx = 0
    //
    // place the new value in a new variable that holds int values, named num
    for (int i = 0; i < str.length(); i++)
    {
        int num = int(str[i]);
        if (num >= 97 && num <= 122)
        {
            vector1[num - 97]++;
            if (vector1[num - 97] > most_repeated)
            {
                most_repeated = vector1[num - 97]; 
                // you can then use vector.find the same value to find the position, you can then add
            }
            // if vec[num-97] > most_repeated{
            // most_repeated_ixs = num-97
            // }
        }
        else if (num >= 65 && num <= 90)
        {
            vector1[num - 65]++;
            if (vector1[num - 65] > most_repeated)
            {
                most_repeated = vector1[num - 65];
            }
        }
    }
    for (int j = 0; j < vector1.size(); j++)
    {
        //std::cout << vector1[j] << std::endl;
    }
    std::cout << most_repeated;
    for (int k = 0; k < vector1.size(); k++)
    {
        if (vector1[k] == most_repeated)
        {
            most_repeated_letter = (k + 97);
        }
    }
    sum_of_consonants = std::accumulate(vector1.begin(), vector1.end(), 0);
    std::cout << most_repeated_letter << std::endl;
    std::cout << "total amount of letters" << sum_of_consonants << std::endl;
    std::cout << "total amount of vowels " <<  << std::endl;
    // print to the console
}
