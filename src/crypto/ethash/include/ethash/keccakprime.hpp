// ethashprime: C/C++ implementation of Ethashprime, the Ethereum Proof of Work algorithm.
// Copyright 2018-2019 Pawel Bylica.
// Licensed under the Apache License, Version 2.0.

#pragma once

#include <crypto/ethash/include/ethash/keccakprime.h>
#include <crypto/ethash/include/ethash/hash_typesprime.hpp>

namespace ethashprime
{
inline hash256 keccak256(const uint8_t* data, size_t size) noexcept
{
    return ethashprime_keccak256(data, size);
}

inline hash256 keccak256(const hash256& input) noexcept
{
    return ethashprime_keccak256_32(input.bytes);
}

inline hash512 keccak512(const uint8_t* data, size_t size) noexcept
{
    return ethashprime_keccak512(data, size);
}

inline hash512 keccak512(const hash512& input) noexcept
{
    return ethashprime_keccak512_64(input.bytes);
}

static constexpr auto keccak256_32 = ethashprime_keccak256_32;
static constexpr auto keccak512_64 = ethashprime_keccak512_64;

}  // namespace ethashprime
