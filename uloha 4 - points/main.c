#include <stdio.h>
#include <stdlib.h>

int main(){

    int a = 74;
    int *pa = &a;

    printf("Address: %p\n", pa);
    printf("Value do: %d\n", *pa);

    *pa = 34;
    printf("Value posle: %d\n", *pa);

    return 0;
}