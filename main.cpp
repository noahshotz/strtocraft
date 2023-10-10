#include <iostream>
#include <vector>

#include "find_combinations.cpp"
#include "dictionary.cpp"

int main()
{
    // Word to convert to sticker craft
    std::string input_str = "KRIMBO";

    std::vector<std::string> combinations = find_combinations(input_str, dictionary);

    std::cout << "Finding combinations for: " << input_str << std::endl;
    std::cout << "Found " << combinations.size() << " possible combinations: " << std::endl;

    // Print the combinations
    for (const std::string &combination : combinations)
    {
        std::cout << combination << std::endl;
    }
    return 0;
}
