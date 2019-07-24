#include <iostream>

#include "UUID.hpp"
#include "StringUtils.hpp"

using namespace data;

UUID4::UUID4(const std::string &uuid4) {
    auto hex_strings = utils::split(uuid4, '-');
    for (auto hex_str : hex_strings)
        std::cout << hex_str << " ";
}