#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

char* vigenere_encrypt(const char* key, const char* text){

    char* keyUpper = malloc(strlen(key)* sizeof(char));
    char* textUpper = malloc(strlen(text)* sizeof(char));
    char* result = malloc(strlen(text)* sizeof(char));
    int len = strlen(text);

    for(int i = 0; i < strlen(key); i++){
        keyUpper[i] = toupper(key[i]);
    }

    for(int i = 0; i < strlen(text); i++){
        textUpper[i] = toupper(text[i]);
    }

    for (int i = 0, j = 0; i < len; i++, j++){

        if(j >= strlen(keyUpper)){ j = 0; }

        if(textUpper[i] > 90 || textUpper[i] < 65){
            result[i] = textUpper[i];
            j--;
        } else {
            result[i] = keyUpper[j];
            result[i] -= 65;
            result[i] += textUpper[i];
            if(result[i] > 90){ result[i] -= 26; }
        }
    }
    return result;
}

char* vigenere_decrypt(const char* key, const char* text){

    char* keyUpper = malloc(strlen(key)* sizeof(char));
    char* textUpper = malloc(strlen(text)* sizeof(char));
    char* result = malloc(strlen(text)* sizeof(char));
    int len = strlen(text);

    for(int i = 0; i < strlen(key); i++){
        keyUpper[i] = toupper(key[i]);
    }

    for(int i = 0; i < strlen(text); i++){
        textUpper[i] = toupper(text[i]);
    }

    for (int i = 0, j = 0; i < len; i++, j++){

        if(j >= strlen(keyUpper)){ j = 0; }

        if(textUpper[i] > 90 || textUpper[i] < 65){
            result[i] = textUpper[i];
            j--;
        } else {
            result[i] -= keyUpper[j];
            result[i] += 65;
            result[i] += textUpper[i];
            if(result[i] < 65){ result[i] += 26; }
        }
    }
    //    74 - 67 = 7         7 + 65 = 72
    return result;
}

char* reverse(const char* text){
    char* reversed = malloc(strlen(text) * sizeof(char));

    for (int i = strlen(text)-1, j = 0; i >= 0; i--, j++)
    {
        reversed[j]=text[i];
        if ((int)reversed[j] >= 97 && (int)reversed[j] <= 122)
        {
            reversed[j] -= 32;
        }
        
    }
    
    return reversed;
}

unsigned char* bit_encrypt(const char* text){

    int len = strlen(text);
    unsigned char *result = calloc(len, sizeof(char));

    for (int i = 0; i < len; i++){
        int bits[8];
        int charDec = (int)text[i];

            // making symbol in bit
        for(int j = 0; j < 8; j++){
            bits[j]=0;
            if(charDec - pow(2, 7 - j) >= 0){
                charDec -= pow(2, 7 - j);
                bits[j] = 1;
            }

        }

            //switching first part
        for(int j = 0; j < 4; j+=2){
            int tmp = bits[j + 1];
            bits[j + 1] = bits[j];
            bits[j] = tmp;
        }

            //XoR second part
        for(int j = 4; j < 8; j++){
            if(bits[j] != bits[j - 4]) {
                bits[j] = 1; 
            } else { 
                bits[j] = 0; 
            }
        }

            // 
        int bites[8] = {128, 64, 32, 16, 8, 4, 2, 1};
        charDec = 0;
        for(int j = 0; j < 8; j++){
            if(bits[j] == 1){
                charDec += bites[j];
            }
        }

        result[i] = (char)charDec;
    }

    return result;
}

char* bit_decrypt(const unsigned char* text){

    int len = strlen((char*)text);
    char *result = calloc(len, sizeof(char));

    for (int i = 0; i < len; i++){
        int bits[8];
        int charDec = (int)text[i];


            /**  making symbol in bit  **/
        for(int j = 0; j < 8; j++){

            bits[j]=0;
            
            if(charDec - pow(2, 7 - j) >= 0){
                charDec -= pow(2, 7 - j);
                bits[j] = 1;
            }
            //printf("%d", bits[j]);
        }

        //printf(" ");


            /**  XoR second part  **/
        for(int j = 4; j < 8; j++){
            if(bits[j] != bits[j - 4]) {
                bits[j] = 1; 
            } else { 
                bits[j] = 0; 
            }
        }


            /**  switching first part  **/
        for(int j = 0; j < 4; j+=2){
            int tmp = bits[j + 1];
            bits[j + 1] = bits[j];
            bits[j] = tmp;
        }


            /**  bit to symbol  **/
        int bites[8] = {128, 64, 32, 16, 8, 4, 2, 1};
        charDec = 0;
        for(int j = 0; j < 8; j++){
            if(bits[j] == 1){
                charDec += bites[j];
            }
        }

        result[i] = (char)charDec;
    }
    //printf("\n");
    return result;
}