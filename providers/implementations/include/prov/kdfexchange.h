/*
 * Copyright 2020 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <stdlib.h>
#include <openssl/crypto.h>
#include "internal/refcount.h"

struct kdf_data_st {
    OPENSSL_CTX *libctx;
    CRYPTO_REF_COUNT refcnt;
    CRYPTO_RWLOCK *lock;
};

typedef struct kdf_data_st KDF_DATA;

KDF_DATA *kdf_data_new(void *provctx);
void kdf_data_free(KDF_DATA *kdfdata);
int kdf_data_up_ref(KDF_DATA *kdfdata);