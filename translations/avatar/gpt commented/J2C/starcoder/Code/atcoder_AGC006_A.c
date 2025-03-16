#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 200 + 10

int f[N];
char b[N];

void getFail(char b[], int m) {
    int j = 0;
    f[0] = f[1] = 0;
    for (int i = 2; i <= m; i++) {
        while (j > 0 && b[j + 1]!= b[i])
            j = f[j];
        if (b[j + 1] == b[i])
            j++;
        f[i] = j;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", b + 1);
    scanf("%s", b + 1 + n);
    getFail(b, n + 1);
    int len = f[n + 1];
    if (len > n)
        len = n;
    printf("%d\n", 2 * n - len);
    return 0;
}

