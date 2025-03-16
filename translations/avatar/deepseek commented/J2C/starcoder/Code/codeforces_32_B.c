#include <stdio.h>
#include <stdlib.h>

int main() {
    char n[100000];
    scanf("%s", n);
    int s = 0;
    for (int i = 0; n[i]!= '\0'; i++) {
        if (n[i] == '.') {
            if (s) {
                printf("1");
                s = 0;
            } else {
                printf("0");
                s = 0;
            }
        } else {
            if (s) {
                printf("2");
                s = 0;
            } else {
                s = 1;
            }
        }
    }
    printf("