#include <iostream>
#include "include/find_combinations.h"
// include dictionary.cpp
#include "src/dictionary.cpp"

int main(int, char**){
    std::cout << "Hello, from strtocraft!\n";

    std::string input_str = "GLASA";

    std::vector<std::string> combinations = find_combinations(input_str, dictionary);

    for (auto combination : combinations) {
        std::cout << combination << std::endl;
    }
}
