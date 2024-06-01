#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *origin = fopen("text.txt", "r");
    FILE *copy = fopen("text copy.txt", "a");


    char line[1024];
    while(fgets(line, 1024, origin) != NULL) {
        fputs(line, copy);
    }

    fclose(origin);
    fclose(copy);

    FILE *file = fopen("text.txt", "w");
    fclose(file);
    
    return 0;
}