#include "util.h"


namespace util {

std::string readFile(const std::filesystem::path& path)
{
    auto&& file = std::ifstream(path);
    auto&& buffer = std::stringstream();
    buffer << file.rdbuf();
    return buffer.str();

}

std::ostream& operator<<(std::ostream& out, const Coord& a)
{
    return out << "(" << a.x << "," << a.y << "," << a.z << ") ";
}

uint64_t distance(const Coord &a, const Coord &b)
{
    uint64_t val = (a.x - b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z);
    return val;
}
} // namespace util
