#include <stdio.h>
#include <string.h>

int main() {
    int x = 0, y = 0;
    int t = 0;
    int n;
    char str[100];
    scanf("%d", &n);
    scanf("%s", str);
    char l[strlen(str)];
    strcpy(l, str);

    for (int i = 0; i < n; i++) {
        if (l[i] != '4' && l[i] != '7') {
            t = 1;
        }
    }

    if (t == 1) {
        printf("NO\n");
    } else {
        for (int i = 0; i < n / 2; i++) {
            x += l[i] - '0';
        }
        for (int i = n - 1; i > (n / 2) - 1; i--) {
            y += l[i] - '0';
        }
        if (x == y) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
