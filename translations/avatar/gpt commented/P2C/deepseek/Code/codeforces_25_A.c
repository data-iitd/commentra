#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int list[n];
    int i;
    for (i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        list[i] = num % 2;
    }

    int odd_count = 0;
    for (i = 0; i < n; i++) {
        if (list[i] == 1) {
            odd_count++;
        }
    }

    if (odd_count == 1) {
        for (i = 0; i < n; i++) {
            if (list[i] == 1) {
                printf("%d\n", i + 1);
                break;
            }
        }
    } else {
        for (i = 0; i < n; i++) {
            if (list[i] == 0) {
                printf("%d\n", i + 1);
                break;
            }
        }
    }

    return 0;
}
