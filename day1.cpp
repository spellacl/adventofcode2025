#include "day1.h"

#include "util.h"

#include <iostream>

namespace Day1 
{
void run()
{
    const std::filesystem::path filename = "./input2";
    std::string input = util::readFile(filename);

    int x = 50; // starting point
    int answer = 0;

    std::string curr;
    std::istringstream f(input);

    while(std::getline(f, curr, '\n'))
    {
        std::cout << x << " " << curr.at(0) << " " << curr.substr(1) << std::endl;

        switch(curr.at(0))
        {
            case 'L':
                x = (x - (std::stoi(curr.substr(1)) % 100) + 100) % 100;
                break;
            case 'R':
                x = (x + (std::stoi(curr.substr(1))%100)) % 100;
                break;
        }
        answer += (x == 0);
    }
    std::cout << "Answer: " << answer << std::endl;
}

}
