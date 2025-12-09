#include "day.h"
#include "util.h"

#include <iostream>

void runDay2(int argc, char **argv)
{
    const std::filesystem::path filename = argv[1];
    std::string input = util::readFile(filename);

    std::string curr;
    std::istringstream f(input);

    std::vector<std::pair<unsigned long long, unsigned long long>> ranges;

    uint64_t answer = 0;
    uint64_t answer2 = 0;
    while(std::getline(f, curr, ',') && !curr.empty())
    {
        auto pos = curr.find('-');

        uint64_t start = std::stoull(curr.substr(0,pos));
        uint64_t end   = std::stoull(curr.substr(pos+1));

        for(uint64_t x = start; x <= end; x++)
        {
            auto x_str = std::to_string(x);
            auto size = x_str.length();
            
            if(size%2 == 0 && x_str.substr(0, size*0.5) ==  x_str.substr( (size*0.5) ))
                answer+=x;

            for(int repeat = 2; repeat <= size; repeat++)
            {
                if(size % repeat) continue; // not possible to have a number repeat evenly
                int seqLen = size / repeat;

                auto seq = x_str.substr(0, seqLen);
                bool repeating = true;
                for(int i = 1; i < repeat; i++)
                {
                    if(seq != x_str.substr(i*seqLen, seqLen))
                    {
                        repeating = false;
                        break;
                    }
                }
                if(repeating)
                {
                    answer2 += x;
                    break;
                }
            }
        }
    }
    std::cout << "Part1: " << answer << std::endl;
    std::cout << "Part2: " << answer2 << std::endl;
}
