#include "rsa.h"

int main() {
    mpz_t plaintext, ciphertext, decrypted;
    mpz_inits(plaintext, ciphertext, decrypted, NULL);

    int bit_size = 128;
    rsa_generate_keys(bit_size);

    mpz_set_ui(plaintext, 123);

    rsa_encrypt(ciphertext, plaintext);

    rsa_decrypt(decrypted, ciphertext);

    gmp_printf("Original Plaintext: %Zd\n", plaintext);
    gmp_printf("Ciphertext: %Zd\n", ciphertext);
    gmp_printf("Decrypted Text: %Zd\n", decrypted);

    mpz_clears(plaintext, ciphertext, decrypted, NULL);

    return 0;
}
