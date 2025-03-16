
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    char s[n], t[n];
    scanf("%s", s);
    scanf("%s", t);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (s[i + j] != t[j]) {
                break;
            }
            if (j == n - i - 1) {
                cnt = n - i;
            }
        }
    }
    printf("%d", 2 * n - cnt);
    return 0;
}

