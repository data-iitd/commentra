
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000000

int main ( ) {
    int n, q, l, r, win, i, j, k, curr, left[MAX], answer[MAX];
    char str[MAX];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &left[i]);
        answer[i] = -1;
    }

    scanf("%d", &q);

    while (q--) {
        scanf("%d %d %d", &l, &r, &win);

        for (i = l; i <= r; i++) {
            if (left[i] != -1) {
                answer[left[i]] = win;
                left[i] = -1;
            }
        }

        answer[win - 1] = 0;

        for (i = 0; i < n; i++) {
            if (left[i] == -1) {
                left[i] = win - 1;
                break;
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }

    printf("\n");

    return 0;
}

