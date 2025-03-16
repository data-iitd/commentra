#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 200 + 10

int f[N];
char b[N];

void getFail(char b[], int m) {
    int j = 0;
    f[0] = f[1] = 0;

    for (int i = 2; i <= m; i++) {
        while (j > 0 && b[j + 1] != b[i])
            j = f[j];
        if (b[j + 1] == b[i])
            j++;
        f[i] = j;
    }
}

int main() {
    int n;
    char s1[N], str[N];
    int cnt = 0;

    scanf("%d", &n);
    scanf("%s", str);
    scanf("%s", s1);

    for (int i = 0; i < n; i++)
        b[++cnt] = str[i];
    for (int i = 0; i < n; i++)
        b[++cnt] = s1[i];

    getFail(b, cnt);

    int len = f[cnt];
    printf("%d\n", 2 * n - len);

    return 0;
}

