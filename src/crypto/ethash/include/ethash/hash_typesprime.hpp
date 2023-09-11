// ethashprime: C/C++ implementation of Ethashprime, the Ethereum Proof of Work algorithm.
// Copyright 2018-2019 Pawel Bylica.
// Licensed under the Apache License, Version 2.0.

#pragma once

#include <crypto/ethash/include/ethash/hash_typesprime.h>

namespace ethashprime
{
using hash256 = ethashprime_hash256;
using hash512 = ethashprime_hash512;
using hash1024 = ethashprime_hash1024;
using hash2048 = ethashprime_hash2048;
}  // namespace ethashprime
