#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    char s[100];
    int index = 0;

    while (n > 0) {
        int x = n % 2;
        n /= 2;
        s[index++] = '0' + x;
    }
    s[index] = '\0';

    int ans = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '1') {
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}
