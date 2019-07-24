#pragma once

#include <algorithm>
#include <bitset>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

namespace utils {

template<typename charT>
static inline std::vector<std::basic_string<charT>> split(std::basic_string<charT> str, 
                                                          charT char_split) {
    std::vector<std::basic_string<charT>> tokens;
    std::basic_stringstream<charT> ss;
    std::basic_string<charT> token;
    for (charT c : str) {
        if (c == char_split) {
            if (ss >> std::noskipws >> token)
                tokens.push_back(std::move(token));
            ss.clear();
        } else
            ss << c;
    }
    if (ss >> std::noskipws >> token)
        tokens.push_back(std::move(token));

    return tokens;
}

static inline std::vector<std::string> split(const char *str, char char_split) {
    return split(std::string(str), static_cast<char>(char_split));
}

static inline std::string lower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return std::move(str);
}

template<size_t T, size_t U>
static inline void copy_bitset(const std::bitset<T> &bitset_src, std::bitset<U> &bitset_dest, int dest_index) {
    for (int i = 0; i < T; ++i)
        bitset_dest.set(dest_index++, bitset_src[i]);
}

static const std::vector<std::bitset<4>> HEX_BITSETS{
    0b0000, 0b0001, 0b0010, 0b0011,
    0b0100, 0b0101, 0b0110, 0b0111,
    0b1000, 0b1001, 0b1010, 0b1011,
    0b1100, 0b1101, 0b1110, 0b1111
};

template<size_t numBitsT>
static inline void fill_bitset_hex(const std::string &hex_str, std::bitset<numBitsT> &bitset) {
    int i = 0;
    std::string lower_hex_str{lower(hex_str)};
    for (char c : lower_hex_str) {
        int val;
        if (c <= '9' && '0' <= c)
            val = c - '0';
        else
            val = 10 + c - 'a';
        copy_bitset(HEX_BITSETS[val], bitset, i);
        i += 4;
    }
}

}