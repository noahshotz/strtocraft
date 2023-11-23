#include <iostream>
#include <map>
#include <vector>
#include <cctype>
#include <string>

#include "../include/find_combinations.h"

std::vector<std::string> find_combinations(std::string &input_str, std::map<std::string, std::string> dictionary)
{

    // convert input string to uppercase
    std::transform(input_str.begin(), input_str.end(), input_str.begin(),
                   [](unsigned char c)
                   { return std::toupper(c); });

    // Create a vector to store the best combinations for each position in the input string
    std::vector<std::vector<std::string>> dp(input_str.length() + 1);

    // Add an empty string at position 0
    dp[0].emplace_back("");

    // Set limit for the number of stickers in a combination
    const std::size_t max_elements = 4;

    for (int i = 1; i <= static_cast<int>(input_str.length()); ++i)
    {
        // Create a vector to store the current combinations
        std::vector<std::string> current_combinations;
        for (int j = 1; j <= i; ++j)
        {
            // Get the substring from j to i
            std::string substring = input_str.substr(j - 1, i - j + 1);

            // Check if the substring is in the dictionary
            if (dictionary.find(substring) != dictionary.end())
            {
                // Get the sticker from the dictionary
                std::string sticker = dictionary[substring];

                // Add the sticker to the current combinations
                for (const std::string &prev_combination : dp[j - 1])
                {
                    // Count the number of elements in prev_combination
                    std::size_t element_count = std::count(prev_combination.begin(), prev_combination.end(), ',') + 1;

                    // Check if adding a new element exceeds the limit
                    if (element_count < max_elements)
                    {
                        current_combinations.push_back(prev_combination + (prev_combination.empty() ? "" : ", ") + sticker);
                    }
                }
            }
        }

        // Sort the current combinations by size
        std::sort(
            current_combinations.begin(),
            current_combinations.end(),
            [](const std::string &a, const std::string &b)
            {
                return a.size() < b.size();
            });

        // Add the current combinations to the dp vector
        dp[i] = (current_combinations.size() <= 4) ? current_combinations : std::vector<std::string>();
    }

    // Return the computed combinations
    return dp.back();
}