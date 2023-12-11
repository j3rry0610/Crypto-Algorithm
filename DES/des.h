#ifndef DES_H
#define DES_H

void des_encrypt(const unsigned char *plain, unsigned char *cipher, const unsigned char *key);
void des_decrypt(const unsigned char *cipher, unsigned char *plain, const unsigned char *key);

#endif
