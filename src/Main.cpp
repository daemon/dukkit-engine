#include <bitset>
#include <iostream>

#include <msgpack.hpp>

#include "Server.hpp"
#include "StringUtils.hpp"
#include "UUID.hpp"

int main() {
    // std::cout << strings << std::endl;
    // for (auto s : strings) {
    //     std::cout << s << " ";
    // }
    std::bitset<64> test;
    utils::fill_bitset_hex("abcdef0123456789", test);
    std::cout << test;
    // auto uuid4 = data::UUID4("0000a01235af");
    msgpack::type::tuple<int, int> src(1, 1);
    // net::server::Server server{"0.0.0.0", 7777};
    // auto connection = server.Listen();
    // auto dlen = connection->Read().size();
}
