#include <stdio.h>
#include "des.h"

int main(){
    unsigned char plain[8];
    unsigned char cipher[8];
    unsigned char key[8];
    for(int i = 0;i < 8; i++){
        plain[i] = 0x1f;
        key[i] = 0x0f;
    }
    printf("start\n");
    des_encrypt(plain, cipher, key);
    des_decrypt(cipher, plain, key);
    for(int i = 0;i < 8; i++){
        printf("%x %x\n", cipher[i], plain[i]);
    }
    return 0;
}
