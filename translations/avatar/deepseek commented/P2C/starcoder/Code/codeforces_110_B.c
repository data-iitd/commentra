
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    char s[n];
    for (int i = 0; i < n; i++) {
        s[i] = LUCKY[i % 4];
    }
    printf("%s", s);
    return 0;
}

