#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long min = LLONG_MAX;
    long a[4], b[4];
    char op[3];
    int i, j, k;
    for (i = 0; i < 4; i++) {
        scanf("%ld", &a[i]);
    }
    for (i = 0; i < 3; i++) {
        scanf("%s", op[i]);
    }
    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                if (k!= j && k!= i) {
                    b[k] = a[k];
                }
            }
            if (op[0] == '+') {
                b[3] = a[i] + a[j];
            } else {
                b[3] = a[i] * a[j];
            }
            if (op[1] == '+') {
                b[3] += a[k];
            } else {
                b[3] *= a[k];
            }
            if (op[2] == '+') {
                b[3] += a[k];
            } else {
                b[3] *= a[k];
            }
            if (b[3] < min) {
                min = b[3];
            }
        }
    }
    printf("%ld\n", min);
    return 0;
}

