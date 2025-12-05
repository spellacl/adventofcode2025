#include "day.h"
#include "util.h"

#include <iostream>

void runDay5(int argc, char **argv)
{
    const std::filesystem::path filename = argv[1];
    std::string input = util::readFile(filename);

    std::string curr;
    std::istringstream f(input);

    std::vector<std::pair<unsigned long long, unsigned long long>> ranges;

    while(std::getline(f, curr, '\n') && !curr.empty())
    {
        auto pos = curr.find("-");

        ranges.push_back(
            std::make_pair<unsigned long long, unsigned long long>(
                std::stoull(curr.substr(0, pos)),
                std::stoull(curr.substr(pos+1))));
    }

    int count = 0;

    while(std::getline(f, curr, '\n'))
    {
        auto value = std::stoull(curr);
        for(auto pair: ranges)
        {
            if(value >= pair.first && value <= pair.second)
            {
                count ++;
                break;
            }
        }
    }
    std::cout << "Answer: " << count << std::endl;
}
