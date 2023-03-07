
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// <idx: value>
// <0: 3, 1: 8, 2:8, 3:0>
// (aaabbbbaab)
int returnGreatestIdx(int current_idx, int max_idx, int current_idx_value, int max_idx_value)
{
    if (current_idx_value >= max_idx_value && current_idx < max_idx)
    {
        return current_idx;
    }
    else if (current_idx_value > max_idx_value)
    {
        return current_idx;
    }

    else
    {
        return max_idx;
    }
}

bool does_file_exist(const char *file)
{
    std::ifstream ifs(file);
    return ifs.good();
}

std::string getInput(int argc, char *argv[])
{
    std::string str;
    std::string temp;
    std::string argv1;
    if (argc == 1)
    {

        // Question is: how to do multiple lines w/o return?
        while (getline(std::cin, temp))
        {
            // getline(std::cin, temp);
            str.insert(0, temp);
        }
        return str;
    }
    else if (argc > 2)
    {
        std::cout << "cannot handle parameter list" << std::endl;
        exit(0);
    }
    else
    {
        // argc = 2
        // argv = ['a.out', 'lorem']
        if (!does_file_exist(argv[1]))
        {
            std::cout << "cannot open input file " << argv[1] << std::endl;
            exit(0);
        }
        // std::ifstream inFS;
        // inFS.open(argv[1]);
        // getline(inFS, str);
        // while (!inFS.fail())
        // {
        //     getline(inFS, str);
        // }

        // Opening the file
        std::ifstream ifs(argv[1]);

        // Loading the text as single long string... no idea how >.>
        std::string str((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
        return str;
    }
}
int main(int argc, char *argv[])
{
    std::string str = getInput(argc, argv);

    int max_idx = 0;
    int max_idx_value = 0;
    // max count for vowels
    int max_v_idx = 0;
    int max_v_idx_value = 0;
    // max count for consonants (non vowels)
    int max_c_idx = 1;
    int max_c_idx_value = 0;

    std::vector<int> vec(26, 0);
    // std::string str = "aaabbbba";
    // std::string str = "Hello World!";

    for (int i = 0; i < str.length(); i++)
    {
        // String to ASCII as int
        int char_ascii = int(str[i]);

        // Clear possible symbols
        int char_idx = -1;

        // Lowercase [a-z]
        if (char_ascii >= 97 && char_ascii <= 122)
        {
            char_idx = char_ascii - 97;
        }
        // Caps [A-Z]
        else if (char_ascii >= 65 && char_ascii <= 90)
        {
            char_idx = char_ascii - 65;
        }

        // Check if not symbol, char_idx = correct vector index (aka letter)
        if (char_idx != -1)
        {
            // Update vector with newest letter count
            vec[char_idx]++;
            int count_of_current_char = vec[char_idx];
            // char_current = char_ascii

            if (char_idx == 0 || char_idx == 4 || char_idx == 8 || char_idx == 14 || char_idx == 20)
            {
                max_v_idx = returnGreatestIdx(char_idx, max_v_idx, count_of_current_char, max_v_idx_value);
                max_v_idx_value = vec[max_v_idx];
            }
            else
            {
                max_c_idx = returnGreatestIdx(char_idx, max_c_idx, count_of_current_char, max_c_idx_value);
                max_c_idx_value = vec[max_c_idx];
            }
            max_idx = returnGreatestIdx(char_idx, max_idx, count_of_current_char, max_idx_value);
            max_idx_value = vec[max_idx];
        }
    }
    std::cout << "Most frequent vowel: " << char(max_v_idx + 97) << " (" << max_v_idx_value << " times)" << std::endl;
    std::cout << "Most frequent consonant: " << char(max_c_idx + 97) << " (" << max_c_idx_value << " times)" << std::endl;
    std::cout << "Most frequent letter, overall: " << char(max_idx + 97) << " (" << max_idx_value << " times)" << std::endl;
}