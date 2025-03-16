#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    char x[100001];
    scanf("%s", x);
    int len = strlen(x);
    char a[100001], b[100001];
    strcpy(a, x);
    strcpy(b, x);
    int a1 = 0, a2 = 0;
    for (int i = 1; i < len; i++) {
        if (a[i] == a[i - 1]) {
            a[i] = a[i] == '1' ? '0' : '1';
            a1++;
        }
    }
    for (int i = len - 1; i > 0; i--) {
        if (b[i] == b[i - 1]) {
            b[i - 1] = b[i - 1] == '1' ? '0' : '1';
            a2++;
        }
    }
    printf("%d\n", min(a1, a2));
    return 0;
}

