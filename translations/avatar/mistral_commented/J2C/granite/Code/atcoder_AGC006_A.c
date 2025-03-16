
#include <stdio.h>
#include <string.h>

#define N 200 + 10

int f[N];
char b[N];

void getFail(char b[], int m) {
    int j = 0;
    f[0] = f[1] = 0;
    for (int i = 2; i <= m; i++) {
        while (j > 0 && b[j + 1]!= b[i]) j = f[j];
        if (b[j + 1] == b[i]) j++;
        f[i] = j;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char s1[N], str[N];
    scanf("%s%s", s1, str);
    int cnt = 0;
    for (int i = 0; i < n; i++) b[++cnt] = str[i];
    for (int i = 0; i < n; i++) b[++cnt] = s1[i];
    getFail(b, cnt);
    int len = f[cnt];
    len = len < n? len : n;
    printf("%d\n", 2 * n - len);
    return 0;
}

