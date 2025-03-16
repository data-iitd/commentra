
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char x[100001];
    scanf("%s", x);
    int a1 = 0, a2 = 0;
    char a[100001], b[100001];
    strcpy(a, x);
    strcpy(b, x);
    for (int i = 1; i < strlen(x); i++) {
        if (a[i] == a[i - 1]) {
            if (a[i] == '1') {
                a[i] = '0';
            } else {
                a[i] = '1';
            }
            a1++;
        }
    }
    for (int i = strlen(x) - 1; i > 0; i--) {
        if (b[i] == b[i - 1]) {
            if (b[i - 1] == '1') {
                b[i - 1] = '0';
            } else {
                b[i - 1] = '1';
            }
            a2++;
        }
    }
    printf("%d\n", a1 < a2? a1 : a2);
    return 0;
}
