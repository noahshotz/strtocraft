#include <iostream>
#include "include/find_combinations.h"
// include dictionary.cpp
#include "src/dictionary.cpp"

int main(int, char **)
{

    std::cout << "Enter your name:" << std::endl;
    std::string input_str;
    std::cin >> input_str;

    std::vector<std::string> combinations = find_combinations(input_str, dictionary);

    std::cout << "Input: " << input_str << std::endl;

    std::size_t i = 1;
    if (combinations.empty())
    {
        std::cout << "No options found." << std::endl;
    }
    else
    {
        for (auto combination : combinations)
        {
            std::cout << "Option " << i << ": " << combination << std::endl;
            i++;
        }
    }
}
