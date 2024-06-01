#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *file = fopen("./text.txt", "r");

    char c;   int x = 0;
    while((c = fgetc(file)) != EOF){
        if (c == '\n'){
            x++;
        }
    }

    printf("Lines count: %d\n", x+1);

    fclose(file);

    return 0;
}