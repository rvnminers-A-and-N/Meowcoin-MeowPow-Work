/* ethashprime: C/C++ implementation of Ethashprime, the Ethereum Proof of Work algorithm.
 * Copyright 2019 Pawel Bylica.
 * Licensed under the Apache License, Version 2.0.
 */

#pragma once

/** The ethashprime library version. */
#define ETHASHPRIME_VERSION "0.5.1-alpha.1"

#ifdef __cplusplus
namespace ethashprime
{
/// The ethashprime library version.
constexpr auto version = ETHASHPRIME_VERSION;

}  // namespace ethashprime
#endif
