#ifndef DES_H
#define DES_H

void des_encipher(const unsigned char *plain, unsigned char *cipher, const unsigned char *key);
void des_decipher(const unsigned char *cipher, unsigned char *plain, const unsigned char *key);

#endif
