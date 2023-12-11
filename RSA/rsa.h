#ifndef RSA_H
#define RSA_H

#include <gmp.h>

void rsa_generate_keys(int bit_size);
void rsa_encrypt(mpz_t ciphertext, const mpz_t plaintext);
void rsa_decrypt(mpz_t plaintext, const mpz_t ciphertext);

#endif
