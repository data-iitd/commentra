#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int n, ans = 0;
    scanf("%s", s);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char x[3];
        scanf("%s", x);
        int a = 0, b = 0;
        for (int j = 0; j < strlen(s); j++) {
            if (s[j] == x[0]) {
                a++;
            } else if (s[j] == x[1]) {
                b++;
            } else {
                ans += a < b ? a : b;
                a = 0;
                b = 0;
            }
        }
        ans += a < b ? a : b;
    }
    printf("%d\n", ans);
    return 0;
}
