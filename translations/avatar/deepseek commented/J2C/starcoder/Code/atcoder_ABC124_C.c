#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char x[100000];
    scanf("%s", x);
    int a1 = 0, a2 = 0;
    for (int i = 1; i < strlen(x); i++) {
        if (x[i] == x[i - 1]) {
            if (x[i] == '1') {
                x[i] = '0';
            } else {
                x[i] = '1';
            }
            a1++;
        }
    }
    for (int i = strlen(x) - 1; i > 0; i--) {
        if (x[i] == x[i - 1]) {
            if (x[i - 1] == '1') {
                x[i - 1] = '0';
            } else {
                x[i - 1] = '1';
            }
            a2++;
        }
    }
    printf("%d\n", a1 < a2? a1 : a2);
    return 0;
}

