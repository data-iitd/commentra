#include <stdio.h>
#include <string.h>

int main() {
    int n, k;
    char a[100];

    scanf("%d %d", &n, &k);
    scanf("%s", a);

    if (k > n / 2) {
        while (k < n) {
            printf("RIGHT\n");
            k++;
        }
    } else {
        while (k > 1) {
            printf("LEFT\n");
            k--;
        }
    }

    if (k == 1) {
        for (int i = 0; i < strlen(a); i++) {
            printf("PRINT %c\n", a[i]);
            if ((i + 1) < strlen(a)) {
                printf("RIGHT\n");
            }
        }
    } else {
        for (int i = strlen(a) - 1; i >= 0; i--) {
            printf("PRINT %c\n", a[i]);
            if ((i - 1) >= 0) {
                printf("LEFT\n");
            }
        }
    }

    return 0;
}

