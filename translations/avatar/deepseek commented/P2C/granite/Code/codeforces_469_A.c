
#include <stdio.h>
#include <stdlib.h>

int main() {
    int max_level, i, j;
    scanf("%d", &max_level);

    int x[max_level], y[max_level];
    for (i = 0; i < max_level; i++) {
        scanf("%d", &x[i]);
    }
    for (j = 0; j < max_level; j++) {
        scanf("%d", &y[j]);
    }

    int k = 0;
    for (i = 0; i < max_level; i++) {
        if (x[i]!= 0) {
            x[k] = x[i];
            k++;
        }
    }
    for (j = 0; j < max_level; j++) {
        if (y[j]!= 0) {
            y[k] = y[j];
            k++;
        }
    }

    int z[max_level];
    int l = 0;
    for (i = 0; i < k; i++) {
        int flag = 0;
        for (j = 0; j < l; j++) {
            if (z[j] == x[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            z[l] = x[i];
            l++;
        }
    }
    for (j = 0; j < k; j++) {
        int flag = 0;
        for (i = 0; i < l; i++) {
            if (z[i] == y[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            z[l] = y[j];
            l++;
        }
    }

    if (l!= max_level) {
        printf("Oh, my keyboard!\n");
    } else {
        printf("I become the guy.\n");
    }

    return 0;
}
