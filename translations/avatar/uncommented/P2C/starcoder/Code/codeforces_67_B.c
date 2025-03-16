#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n, k, m, i, j, p, l;
    int *M;
    n = atoi(argv[1]);
    k = atoi(argv[2]);
    M = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        M[i] = atoi(argv[i + 3]);
    }
    m = 0;
    for (j = 0; j < n; j++) {
        for (p = 0; p < n; p++) {
            if (0 == M[p]) {
                printf("%d ", p + 1);
                break;
            }
        }
        for (l = p + 1 - k; l < p; l++) {
            M[l] -= 1;
        }
        M[p] -= 1;
    }
    return 0;
}
