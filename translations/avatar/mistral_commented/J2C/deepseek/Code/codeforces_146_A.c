#include <stdio.h>
#include <string.h>

int main() {
    int x = 0, y = 0;
    int t = 0;
    int n = 0;
    char str[100];
    char l[100];

    scanf("%d", &n);
    scanf("%s", str);

    strcpy(l, str);

    for (int i = 0; i < n; i++) {
        if (l[i] != '4' && l[i] != '7') {
            t = 1;
        }
    }

    if (t == 1) {
        printf("NO\n");
    } else {
        int sumX = 0;
        int sumY = 0;

        for (int i = 0; i < n / 2; i++) {
            sumX += l[i] - '0';
        }

        for (int i = n - 1; i > (n / 2) - 1; i--) {
            sumY += l[i] - '0';
        }

        if (sumX == sumY) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
