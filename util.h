#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>

namespace util
{
std::string readFile(const std::filesystem::path& path);
}
