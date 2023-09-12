// ethashprime: C/C++ implementation of Ethashprime, the Ethereum Proof of Work algorithm.
// Copyright 2018-2019 Pawel Bylica.
// Licensed under the Apache License, Version 2.0.

#pragma once

#include <crypto/ethash/include/ethash/ethashprime.hpp>

#include <string>

template <typename HashPrime>
inline std::string to_hex(const HashPrime& h)
{
    static const auto hex_chars = "0123456789abcdef";
    std::string str;
    str.reserve(sizeof(h) * 2);
    for (auto b : h.bytes)
    {
        str.push_back(hex_chars[uint8_t(b) >> 4]);
        str.push_back(hex_chars[uint8_t(b) & 0xf]);
    }
    return str;
}

inline ethashprime::hash256 to_hash256Prime(const std::string& hex)
{
    auto parse_digit = [](char d) -> int { return d <= '9' ? (d - '0') : (d - 'a' + 10); };

    ethashprime::hash256 hash = {};
    for (size_t i = 1; i < hex.size(); i += 2)
    {
        int h = parse_digit(hex[i - 1]);
        int l = parse_digit(hex[i]);
        hash.bytes[i / 2] = uint8_t((h << 4) | l);
    }
    return hash;
}

/// Comparison operator for hash256 to be used in unit tests.
inline bool operator==(const ethashprime::hash256& a, const ethashprime::hash256& b) noexcept
{
    return std::memcmp(a.bytes, b.bytes, sizeof(a)) == 0;
}

inline bool operator!=(const ethashprime::hash256& a, const ethashprime::hash256& b) noexcept
{
    return !(a == b);
}

inline const ethashprime::epoch_context& get_ethashprime_epoch_context_0() noexcept
{
    static ethashprime::epoch_context_ptr context = ethashprime::create_epoch_context(0);
    return *context;
}
