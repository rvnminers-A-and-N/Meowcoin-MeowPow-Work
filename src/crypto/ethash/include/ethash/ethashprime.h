/* ethashprime: C/C++ implementation of Ethashprime, the Ethereum Proof of Work algorithm.
 * Copyright 2018-2019 Pawel Bylica.
 * Licensed under the Apache License, Version 2.0.
 */

#pragma once

#include <crypto/ethash/include/ethash/hash_typesprime.h>

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
#define NOEXCEPT noexcept
#else
#define NOEXCEPT
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * The Ethashprime algorithm revision implemented as specified in the Ethashprime spec
 * https://github.com/ethereum/wiki/wiki/Ethashprime.
 */
#define ETHASHPRIME_REVISION "23"

#define ETHASHPRIME_EPOCH_LENGTH 7500
#define ETHASHPRIME_LIGHT_CACHE_ITEM_SIZE 64
#define ETHASHPRIME_FULL_DATASET_ITEM_SIZE 128
#define ETHASHPRIME_NUM_DATASET_ACCESSES 64


struct ethashprime_epoch_context
{
    const int epoch_number;
    const int light_cache_num_items;
    const union ethashprime_hash512* const light_cache;
    const uint32_t* const l1_cache;
    const int full_dataset_num_items;
};


struct ethashprime_epoch_context_full;


struct ethashprime_result
{
    union ethashprime_hash256 final_hash;
    union ethashprime_hash256 mix_hash;
};


/**
 * Calculates the number of items in the light cache for given epoch.
 *
 * This function will search for a prime number matching the criteria given
 * by the Ethashprime so the execution time is not constant. It takes ~ 0.01 ms.
 *
 * @param epoch_number  The epoch number.
 * @return              The number items in the light cache.
 */
int ethashprime_calculate_light_cache_num_items(int epoch_number) NOEXCEPT;


/**
 * Calculates the number of items in the full dataset for given epoch.
 *
 * This function will search for a prime number matching the criteria given
 * by the Ethashprime so the execution time is not constant. It takes ~ 0.05 ms.
 *
 * @param epoch_number  The epoch number.
 * @return              The number items in the full dataset.
 */
int ethashprime_calculate_full_dataset_num_items(int epoch_number) NOEXCEPT;

/**
 * Calculates the epoch seed hash.
 * @param epoch_number  The epoch number.
 * @return              The epoch seed hash.
 */
union ethashprime_hash256 ethashprime_calculate_epoch_seed(int epoch_number) NOEXCEPT;


struct ethashprime_epoch_context* ethashprime_create_epoch_context(int epoch_number) NOEXCEPT;

/**
 * Creates the epoch context with the full dataset initialized.
 *
 * The memory for the full dataset is only allocated and marked as "not-generated".
 * The items of the full dataset are generated on the fly when hit for the first time.
 *
 * The memory allocated in the context MUST be freed with ethashprime_destroy_epoch_context_full().
 *
 * @param epoch_number  The epoch number.
 * @return  Pointer to the context or null in case of memory allocation failure.
 */
struct ethashprime_epoch_context_full* ethashprime_create_epoch_context_full(int epoch_number) NOEXCEPT;

void ethashprime_destroy_epoch_context(struct ethashprime_epoch_context* context) NOEXCEPT;

void ethashprime_destroy_epoch_context_full(struct ethashprime_epoch_context_full* context) NOEXCEPT;


/**
 * Get global shared epoch context.
 */
const struct ethashprime_epoch_context* ethashprime_get_global_epoch_context(int epoch_number) NOEXCEPT;

/**
 * Get global shared epoch context with full dataset initialized.
 */
const struct ethashprime_epoch_context_full* ethashprime_get_global_epoch_context_full(
    int epoch_number) NOEXCEPT;


struct ethashprime_result ethashprime_hash(const struct ethashprime_epoch_context* context,
    const union ethashprime_hash256* header_hash, uint64_t nonce) NOEXCEPT;

bool ethashprime_verify(const struct ethashprime_epoch_context* context,
    const union ethashprime_hash256* header_hash, const union ethashprime_hash256* mix_hash, uint64_t nonce,
    const union ethashprime_hash256* boundary) NOEXCEPT;

bool ethashprime_verify_final_hash(const union ethashprime_hash256* header_hash,
    const union ethashprime_hash256* mix_hash, uint64_t nonce,
    const union ethashprime_hash256* boundary) NOEXCEPT;

#ifdef __cplusplus
}
#endif
