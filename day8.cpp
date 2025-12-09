#include "day.h"
#include "util.h"

#include <iostream>
#include <numeric>
#include <unordered_set>

typedef struct {
    uint64_t dist;
    int idx;
    int idy;
} Data;

void runDay8(int argc, char **argv)
{
    const std::filesystem::path filename = argv[1];
    std::string input = util::readFile(filename);

    std::string curr;
    std::istringstream f(input);

    std::vector<util::Coord> coords;

    while(std::getline(f, curr, '\n') && !curr.empty())
    {
        auto pos = curr.find(",");
        auto pos2 = curr.find(",", pos+1);

        coords.push_back(
                {
                std::stoi(curr.substr(0, pos)), 
                std::stoi(curr.substr(pos+1, pos2)),
                std::stoi(curr.substr(pos2+1)) });
    }

    std::vector <Data> data;

    for(int i = 0; i < coords.size(); i++)
    {
        for(int j = i+1; j < coords.size(); j++)
        {
            data.push_back({ util::distance(coords.at(i), coords.at(j)), i, j });
        }
    }

    std::sort(data.begin(), data.end(), [](Data a, Data b)
                                          {
                                            return a.dist < b.dist;
                                          });

    std::vector< std::unordered_set <int> > circuits;
    for(int i = 0; i < coords.size(); i++)
        circuits.push_back( {i} );

    for(int i = 0; i < std::atoi(argv[2]); i++)
    {
        auto d = data.at(i);
        std::cout  << d.dist << " " << d.idx << " " << d.idy << " " << coords.at(d.idx) << coords.at(d.idy) << std::endl;

        int found_idx = -1;
        int found_idy = -1;
        for(int j = 0; j < circuits.size(); j++)
        {
            if(circuits.at(j).contains(d.idx)) found_idx = j;
            if(circuits.at(j).contains(d.idy)) found_idy = j;
        }

        if(found_idx != found_idy )
        {
            circuits.at(found_idx).merge(circuits.at(found_idy));
            circuits.erase(circuits.begin() + found_idy);
        }

        /*for(auto c : circuits )
        {
            for( auto x : c )
                std::cout << x << " ";
            std::cout << std::endl;
        }*/
    }

    int answer = 1;
    std::sort(circuits.begin(), circuits.end(), [](std::unordered_set<int> a, std::unordered_set<int> b)
                                                {
                                                    return a.size() > b.size();
                                                } );

    for(int i = 0 ; i < 3; i++)
    {
        answer *= circuits.at(i).size();
    }
    std::cout << answer << std::endl;
}
