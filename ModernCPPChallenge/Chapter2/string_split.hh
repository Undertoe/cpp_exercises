#pragma once

#include <string_view>
#include <vector>

namespace Chapter2
{

std::vector<std::string_view> string_split(std::string_view str, char delimiter);

// std::vector<std::string_view> string_split(std::string_view str, std::vector<char> delimiters);

}  // namespace Chapter2