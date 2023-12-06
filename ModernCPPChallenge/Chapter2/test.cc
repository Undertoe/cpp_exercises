#include <catch2/catch.hpp>

#include "ipv4.hh"
#include "string_split.hh"

TEST_CASE("string_split, single delimiter")
{
    std::string_view str{"one,two,three"};
    std::vector<std::string_view> result{Chapter2::string_split(str, ',')};
    REQUIRE(result.size() == 3);
    REQUIRE(result[0] == "one");
    REQUIRE(result[1] == "two");
    REQUIRE(result[2] == "three");
}

TEST_CASE("ipv4::to_string")
{
    {
        Chapter2::IPv4 ipv4("127.0.0.1");
        REQUIRE(ipv4.toString() == "127.0.0.1");
        REQUIRE(ipv4.isValid() == true);
    }
    {
        Chapter2::IPv4 bad("123.221.1");
        REQUIRE(bad.isValid() == false);
    }
    {
        Chapter2::IPv4 bad("adf.123.41.1");
        REQUIRE(bad.isValid() == false);
    }
    {
        Chapter2::IPv4 bad("123.566.221.213");
        REQUIRE(bad.isValid() == false);
    }
}