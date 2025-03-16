```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int s, x, d = 2;
    scanf("%d", &s);
    int *a = (int *)malloc(1000000 * sizeof(int)); // Allocate memory for the set
    a[0] = s;

    while (1) {
        if (s % 2 == 0) {
            x = s / 2;
            for (int i = 0; i < d; i++) {
                if (a[i] == x) {
                    printf("%d\n", d);
                    free(a);
                    return 0;
                }
            }
            a[d] = x;
        } else {
            x = 3 * s + 1;
            for (int i = 0; i < d; i++) {
                if (a[i] == x) {
                    printf("%d\n", d);
                    free(a);
                    return 0;
                }
            }
            a[d] = x;
        }
        s = x;
        d++;
    }

    free(a);
    return 0;
}
