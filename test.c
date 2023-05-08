#include <stdio.h>

int main () {
    int i[1] = { 1 };
    int j[1] = { 1 };
    printf("%d", memcmp(i, j, sizeof(i)));


    return 0;
}