#include <stdio.h>
#include <gmp.h>
#include <time.h>

void generate_prime(mpz_t prime, int bit_size, gmp_randstate_t state) {
    mpz_urandomb(prime, state, bit_size);
    mpz_nextprime(prime, prime);
}

void rsa_generate_keys(int bit_size) {
    mpz_t p, q, n, e, d, phi;
    mpz_inits(p, q, n, e, d, phi, NULL);

    gmp_randstate_t state;
    gmp_randinit_default(state);

    gmp_randseed_ui(state, time(NULL));
    generate_prime(p, bit_size, state);

    gmp_randseed_ui(state, time(NULL) + 1);
    generate_prime(q, bit_size, state);

    mpz_mul(n, p, q);
    mpz_sub_ui(p, p, 1);
    mpz_sub_ui(q, q, 1);
    mpz_mul(phi, p, q);

    mpz_set_ui(e, 65537);
    mpz_invert(d, e, phi);

    gmp_printf("p: %Zd\nq: %Zd\ne: %Zd\nd: %Zd\nn: %Zd\nphi: %Zd\n", p, q, e, d, n, phi);

    FILE *fp = fopen("public_key.txt", "w");
    mpz_out_str(fp, 10, e);
    fprintf(fp, "\n");
    mpz_out_str(fp, 10, n);
    fclose(fp);

    fp = fopen("private_key.txt", "w");
    mpz_out_str(fp, 10, d);
    fprintf(fp, "\n");
    mpz_out_str(fp, 10, n);
    fclose(fp);

    mpz_clears(p, q, n, e, d, phi, NULL);
}

void rsa_encrypt(mpz_t ciphertext, const mpz_t plaintext) {
    mpz_t e, n;
    mpz_inits(e, n, NULL);

    FILE *fp = fopen("public_key.txt", "r");
    if (fp != NULL) {
        mpz_inp_str(e, fp, 10);
        mpz_inp_str(n, fp, 10);
        fclose(fp);

        if (mpz_cmp(plaintext, n) >= 0) {
            printf("Error: Plaintext is too large.\n");
        } else {
            mpz_powm(ciphertext, plaintext, e, n);
        }
    } else {
        printf("Error: Unable to open public key file.\n");
    }

    mpz_clears(e, n, NULL);
}

void rsa_decrypt(mpz_t plaintext, const mpz_t ciphertext) {
    mpz_t d, n;
    mpz_inits(d, n, NULL);

    FILE *fp = fopen("private_key.txt", "r");
    if (fp != NULL) {
        mpz_inp_str(d, fp, 10);
        mpz_inp_str(n, fp, 10);
        fclose(fp);

        if (mpz_cmp(ciphertext, n) >= 0) {
            printf("Error: Ciphertext is too large.\n");
        } else {
            mpz_powm(plaintext, ciphertext, d, n);
        }
    } else {
        printf("Error: Unable to open private key file.\n");
    }

    mpz_clears(d, n, NULL);
}
