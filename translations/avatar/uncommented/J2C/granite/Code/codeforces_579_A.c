
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    char s[100];
    int i = 0;
    while (n > 0) {
        int x = n % 2;
        n /= 2;
        s[i++] = x + '0';
    }
    int ans = 0;
    for (int j = 0; j < i; j++) {
        if (s[j] == '1') {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
// END-OF-CODE