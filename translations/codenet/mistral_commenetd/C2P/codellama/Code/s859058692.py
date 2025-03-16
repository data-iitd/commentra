#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 1000000

int main(void) {
    int n, i, min, max;
    long sum = 0;
    int m;

    scanf("%d\n", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &m);
        sum += m;

        if (min > m) {
            min = m;
        }

        if (max < m) {
            max = m;
        }
    }

    printf("%d %d %ld\n", min, max, sum);
}

