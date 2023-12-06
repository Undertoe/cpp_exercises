#include "string_split.hh"

std::vector<std::string_view>
Chapter2::string_split(std::string_view str, char delimiter)
{
    std::vector<std::string_view> result;
    size_t start{0};
    size_t end{str.find_first_of(delimiter)};
    while (end <= std::string_view::npos)
    {
        result.emplace_back(str.substr(start, end - start));
        if (end == std::string_view::npos)
        {
            break;
        }
        start = end + 1;
        end = str.find_first_of(delimiter, start);
    }
    return result;
}

// std::vector<std::string_view>
// Chapter2::string_split(std::string_view str, std::vector<char> delimiters)
// {
//     std::vector<std::string_view> result;
//     size_t start{0};
//     size_t end{str.find_first_of(delimiter)};
//     while (end <= std::string_view::npos)
//     {
//         result.emplace_back(str.substr(start, end - start));
//         if (end == std::string_view::npos)
//         {
//             break;
//         }
//         start = end + 1;
//         end = str.find_first_of(delimiter, start);
//     }
//     return result;
// }
