

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char x[100001];
    scanf("%s", x);
    int a1 = 0, a2 = 0;
    int n = strlen(x);
    char a[n], b[n];
    strcpy(a, x);
    strcpy(b, x);
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            if (a[i] == '1') {
                a[i] = '0';
            } else {
                a[i] = '1';
            }
            a1++;
        }
    }
    for (int i = n - 1; i > 0; i--) {
        if (b[i] == b[i - 1]) {
            if (b[i - 1] == '1') {
                b[i - 1] = '0';
            } else {
                b[i - 1] = '1';
            }
            a2++;
        }
    }
    printf("%d\n", fmin(a1, a2));
    return 0;
}
