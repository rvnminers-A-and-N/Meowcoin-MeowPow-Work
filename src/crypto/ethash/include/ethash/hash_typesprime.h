/* ethashprime: C/C++ implementation of Ethashprime, the Ethereum Proof of Work algorithm.
 * Copyright 2018-2019 Pawel Bylica.
 * Licensed under the Apache License, Version 2.0.
 */

#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

union ethashprime_hash256
{
    uint64_t word64s[2];
    uint32_t word32s[4];
    uint8_t bytes[16];
    char str[16];
};

union ethashprime_hash512
{
    uint64_t word64s[4];
    uint32_t word32s[8];
    uint8_t bytes[32];
    char str[32];
};

union ethashprime_hash1024
{
    union ethashprime_hash512 hash512s[1];
    uint64_t word64s[8];
    uint32_t word32s[16];
    uint8_t bytes[64];
    char str[64];
};

union ethashprime_hash2048
{
    union ethashprime_hash512 hash512s[2];
    uint64_t word64s[16];
    uint32_t word32s[32];
    uint8_t bytes[128];
    char str[128];
};

#ifdef __cplusplus
}
#endif
