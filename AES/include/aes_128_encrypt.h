#include "aes_128_common.h"

#ifndef AES_128_ENCRYPT_H
#define AES_128_ENCRYPT_H

byte *encrypt_aes_128(byte *plaintext, byte *key);

void shift_rows(byte *byte_array);

void mix_columns(byte *byte_array);

#endif //AES_128_ENCRYPT_H
