#include <stdio.h>
#include <stdlib.h>
#include "topsecret.h"

int main(){

    unsigned char* encrypted_bit;
    char* encrypted_vig;
    char* decrypted_bit;
    char* decrypted_vig;

    char* reversed = reverse("Susibaka");
    printf("Reverse:   %s\n", reversed);
    // "!DLROW OLLEH" or "AKABISUS"

        printf("\n");

    encrypted_vig = vigenere_encrypt("CoMPuTeR", "Hello world!");
    printf("Vigenere:   %s\n", encrypted_vig);
    // "JSXAI PSINR!"

    decrypted_vig = vigenere_decrypt("CoMPuTeR", encrypted_vig);
    printf("DeVigenere:   %s\n", decrypted_vig);

        printf("\n");

    encrypted_bit = bit_encrypt("Susibaka and pes");
    printf("Bit:   ");
    for(int i = 0; i < 16; i++){
        printf("%x ", encrypted_bit[i]);
    }

        printf("\n");

    decrypted_bit = bit_decrypt(encrypted_bit);
    printf("DeBit:   %s", decrypted_bit);
    // for(int i = 0; i < 16; i++){
    //     printf("%c", decrypted[i]);
    // }

        printf("\n");

    free(reversed);
    free(encrypted_vig);
    free(encrypted_bit);
    free(decrypted_bit);
    free(decrypted_vig);

    return 0;
}