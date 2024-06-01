#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main ()
{
    /**
     * r - read, нельзя редактировать, не создает файл
     * w - write, нельзя считывать, попытается создать файл
     * a - append, нельзя считывать, попытается создать файл
     */
    FILE *file = fopen("./test.txt", "r");
 
    if (file == NULL) {
        printf("Cannot open file\n");
        return 1;
    }
 
    /**
     * SEEK_SET - начало файла
     * SEEK_END - в конец файла
     * SEEK_CUR - нынешняя позиция
     */
    char line[1024];
    fgets(line, 1024, file);
    fseek(file, 5, SEEK_CUR);
 
    fgets(line, 1024, file);
    printf(":%s\n", line);
 
    // char c;
    // while ((c = fgetc(file)) != EOF) {
    //  printf(":%c\n", c);
    // }
 
    // char line[1024];
 
    // while (fgets(line, 1024, file) != NULL) {
    //  printf(":%s\n", line);
    // }
 
    // fputc('H', file);
    // fputc('2', file);
    // fputc('O', file);
 
    // fputs("Hello, world!\n", file);
    // fputs("Hello, world!2", file);
 
    // char name[20] = "Nazar";
    // int age = 55;
    // fprintf(file, "Hello %s - %d\n", name, age);
 
    // char name[20] = "Madonna";
    // fprintf(file, "Hello %s\n", name);
 
 
    fclose(file);
 
    return 0;
}