#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int list[n];
    int i;
    for (i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        list[i] = x % 2;
    }

    int sum = 0;
    for (i = 0; i < n; i++) {
        sum += list[i];
    }

    if (sum == 1) {
        for (i = 0; i < n; i++) {
            if (list[i] == 1) {
                printf("The first number with remainder 1 is: %d\n", i + 1);
                break;
            }
        }
    } else {
        for (i = 0; i < n; i++) {
            if (list[i] == 0) {
                printf("The first number with remainder 0 is: %d\n", i + 1);
                break;
            }
        }
    }

    return 0;
}
