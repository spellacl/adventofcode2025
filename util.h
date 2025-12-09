#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>

namespace util
{

typedef struct coord {
    int x; int y; int z;
} Coord;

std::string readFile(const std::filesystem::path& path);

uint64_t distance(const Coord &a, const Coord &b);

std::ostream& operator<<(std::ostream& out, const Coord& a);
}
