#include <iostream>
#include <map>
#include <vector>

std::vector<std::string> find_combinations(const std::string &input_str, std::map<std::string, std::string> dictionary)
{
    // Create a vector to store the best combinations for each position in the input string
    std::vector<std::vector<std::string>> dp(input_str.length() + 1);
    // Add an empty string at position 0
    dp[0].emplace_back("");

    for (int i = 1; i <= static_cast<int>(input_str.length()); ++i)
    {
        std::vector<std::string> current_combinations;
        for (int j = 1; j <= i; ++j)
        {
            std::string substring = input_str.substr(j - 1, i - j + 1);

            if (dictionary.find(substring) != dictionary.end())
            {
                std::string sticker = dictionary[substring];

                for (const std::string &prev_combination : dp[j - 1])
                {
                    current_combinations.push_back(prev_combination + (prev_combination.empty() ? "" : ", ") + sticker);
                }
            }
        }

        std::sort(
            current_combinations.begin(),
            current_combinations.end(),
            [](const std::string &a, const std::string &b)
            {
                return a.size() < b.size();
            });

        dp[i] = (current_combinations.size() <= 4) ? current_combinations : std::vector<std::string>();
    }

    // Return the computed combinations
    return dp.back();
}