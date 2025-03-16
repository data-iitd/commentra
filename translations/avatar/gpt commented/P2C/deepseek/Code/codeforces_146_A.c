#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int number[n];
    char temp[n + 1];
    scanf("%s", temp);

    for (int i = 0; i < n; i++) {
        number[i] = temp[i] - '0';
    }

    int h1 = 0, h2 = 0, x = 0;

    for (int i = 0; i < n; i++) {
        if (number[i] != 4 && number[i] != 7) {
            printf("NO\n");
            x = 1;
            break;
        }

        if (i < n / 2) {
            h1 += number[i];
        } else {
            h2 += number[i];
        }
    }

    if (!x) {
        if (h1 == h2) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
