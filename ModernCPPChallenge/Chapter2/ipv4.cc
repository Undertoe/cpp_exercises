#include "ipv4.hh"

Chapter2::IPv4::IPv4(std::string_view address)
{
    auto parts = string_split(address, '.');
    if (parts.size() != 4)
    {
        return;
    }

    // for(auto & [addrint, addrStr] : zip(m_address, parts)) would be preferred but we can't have nice things.
    for (int i = 0; i < 4; ++i)
    {
        // m_address[i] = static_cast<unsigned char>(std::stoi(std::string(parts[i])));
        auto [ptr, ec] = std::from_chars(parts[i].begin(), parts[i].end(), m_address[i]);
        if (ec != std::errc())
        {
            return;
        }
        if (m_address[i] > 255)
        {
            return;
        }
    }
    valid = true;
}

bool
Chapter2::IPv4::isValid() const
{
    return valid;
}

std::string
Chapter2::IPv4::toString() const
{
    if (!valid)
    {
        return "";
    }
    std::string retval;
    for (const auto& addr : m_address)
    {
        retval += std::to_string(addr);
        if (addr != m_address.back())
        {
            retval += ".";
        }
    }
    return retval;
}