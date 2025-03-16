
#include <stdio.h>
#include <stdlib.h>

int main() {
    char n[100000];
    scanf("%s", n);
    int a[5] = {10, 100, 1000, 10000, 100000};
    int new = 0;
    for (int i = 0; i < strlen(n); i++) {
        new += n[i] - '0';
    }
    if (new == 10) {
        printf("10");
    } else {
        printf("%d", new);
    }
    printf("\n