#pragma once

// write a class that represents an IPv4 address.  Implement the functions require to be able to read and write such an address from or to the console.  The user should be able to input values in dotted form, such as "127.0.0.1" or "168.192.0.11".  This is also the form which ipv4 address should be formatted in an output stream

#include <array>
#include <charconv>
#include <string>
#include <string_view>

#include "string_split.hh"

namespace Chapter2
{
class IPv4
{
public:
    IPv4(std::string_view address);

    bool isValid() const;
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const IPv4& address);
    friend std::istream& operator>>(std::istream& is, IPv4& address);

private:
    std::array<unsigned char, 4> m_address{0, 0, 0, 0};
    bool valid{false};
};
}  // namespace Chapter2