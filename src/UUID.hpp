#pragma once

#include <bitset>
#include <string>
#include <utility>

namespace data {

class UUID4 {
public:
    explicit UUID4(const std::string &);
    explicit UUID4(std::bitset<128> bitset) : m_UUID(std::move(bitset)) {}
private:
    std::bitset<128> m_UUID;
};

}