#include "day.h"

#include "util.h"

#include <iostream>

void runDay3(int argc, char**argv)
{
    const std::filesystem::path filename = argv[1];
    std::string input = util::readFile(filename);

    std::string curr;
    std::istringstream f(input);

    auto largest_number = [](const std::string s, const int ndigits) -> std::string
        {
            int lenS = s.length();
            int start_pos = 0;

            std::string answer;

            for(int iter = ndigits; iter > 0; iter--)
            {
                int endpoint = lenS - iter + 1; 
                auto subS = s.substr(start_pos, endpoint - start_pos);

                int max = -1;
                int max_idx;
                for(int i = 0; i < subS.length(); i++)
                {
                    int value = std::stoi(subS.substr(i, 1));
                    if(max < value)
                    {
                        max = value;
                        max_idx = i;
                    }
                }
                answer.push_back(subS.at(max_idx));
                start_pos = start_pos + max_idx + 1;
            }
            return answer;
        };

    uint64_t answer = 0;
    while(std::getline(f, curr, '\n'))
    {
        auto big = largest_number(curr, 12);
        std::cout << curr << " " << big << std::endl;
        answer += std::stoull(big);
    }
    std::cout << "Part 1: " << answer << std::endl;
}
