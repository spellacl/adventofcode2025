#include "util.h"


namespace util {

std::string readFile(const std::filesystem::path& path)
{
    auto&& file = std::ifstream(path);
    auto&& buffer = std::stringstream();
    buffer << file.rdbuf();
    return buffer.str();

}

} // namespace util
