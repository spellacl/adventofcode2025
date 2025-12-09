#include "day.h"

#include "util.h"

#include <iostream>

void runDay1(int argc, char**argv)
{
    const std::filesystem::path filename = argv[1];
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
            
        int turn = std::stoi(curr.substr(1));
        answer2 += turn / 100;
        turn %= 100;
        
        if(curr.at(0) == 'L') new_val = x - turn;
        else new_val = x + turn;

        x = (new_val+100) % 100;

        answer += (x == 0);
        answer2 += x == 0 || (old_x != 0 && (new_val < 0 || new_val > 100));
    }
    std::cout << "Answer: " << answer << " " << answer2 << std::endl;
}
