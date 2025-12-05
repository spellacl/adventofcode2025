#include "day.h"

#include "util.h"

#include <iostream>

void runDay1()
{
    const std::filesystem::path filename = "./input2";
    std::string input = util::readFile(filename);

    int x = 50; // starting point
    int answer = 0, answer2 = 0;

    std::string curr;
    std::istringstream f(input);

    while(std::getline(f, curr, '\n'))
    {
        std::cout << x << " " << curr.at(0) << " " << curr.substr(1) << std::endl;

        int old_x = x;
        int new_val;
        switch(curr.at(0))
        {
            case 'L':
                new_val = x - (std::stoi(curr.substr(1)) % 100);
                x = (new_val + 100) % 100;
                break;
            case 'R':
                new_val = x + (std::stoi(curr.substr(1)) % 100);
                x = new_val % 100;
                break;
        }
        std::cout << old_x << " " << new_val << " " << x << std::endl;

        answer  += (x == 0);
        answer2 += (x == 0) || (old_x != 0 && x != new_val) ;
    }
    std::cout << "Answer: " << answer << " " << answer2 << std::endl;
}
