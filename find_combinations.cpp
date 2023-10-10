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

int main()
{
    // Define dictionary for substrings and corresponding stickers
    std::map<std::string, std::string> dictionary = {
        {"A", "Apeks"},
        {"B", "Flipsid3 Tactics"},
        {"C", "London Conspiracy"},
        {"D", "d_placeholder"},
        {"E", "e_placeholder"},
        {"F", "FaZe Clan"},
        {"G", "LGB eSports"},
        {"H", "Heroic"},
        {"I", "Flashbang"},
        {"J", "JT Autograph"},
        {"K", "SK Gaming"},
        {"L", "CR4ZY"},
        {"M", "Clan-Mystik"},
        {"N", "Team EnvyUs"},
        {"O", "Evil Geniuses"},
        {"P", "Pain Gaming"},
        {"Q", "q_placeholder"},
        {"R", "Reason Gaming"},
        {"S", "Splyce"},
        {"T", "Titan"},
        {"U", "Teamwork"},
        {"V", "Vitality"},
        {"W", "INS Autograph (Rio 2022)"},
        {"X", "Vexed Gaming"},
        {"Y", "y_placeholder"},
        {"Z", "z_placeholder"},
        {"GL", "GamerLegion"},
        {"GG", "Good Game"},
        {"EZ", "EZ"},
        {"REKT", "REKT"},
        {"RUSH", "RUSH"},
        {"PEEK", "PEEK"},
        {"GO", "GO"},
        {"BIG", "BIG"},
        {"DICK", "DICK"},
        {"IM", "iM"},
        {"OG", "OpTic Gaming"},
        {"HR", "HellRaisers"},
        {"HF", "Have Fun"},
        {"NRG", "NRG"},
        {"BIT", "b1t Autograph"},
        {"ART", "arT Autgraph"},
        {"RAIN", "rain Autograph"},
        {"KEI", "KEi Autograph"},
        {"SDY", "SDY Autograph"},
        {"JT", "JT Autograph"},
        {"TEZ", "TeSeS Autograph"},
        {"I SUCK", "isak Autograph"},
        {"FX", "Fluxo"},
        {"INS", "INS Autograph"},
        {"LIL", "IHC Esports"},
        {"LNZ", "LNZ Autograph"},
        {"NEO", "NEO Autograph"},
        {"OBO", "oBo Autograph"},
        {"FER", "FER Autograph"}};

    // Word to convert to sticker craft
    std::string input_str = "GLOCK";

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
