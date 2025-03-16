#include <stdio.h>

int main() {
    char LUCKY[] = "abcd";
    int n;
    scanf("%d", &n);
    char s[n+1];
    for (int i = 0; i < n; i++) {
        s[i] = LUCKY[i % 4];
    }
    s[n] = '\0';
    printf("%s\n", s);
    return 0;
}
