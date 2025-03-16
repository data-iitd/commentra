#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
#include <float.h>

#define MAX_INPUT 1000000

int main() {
    int N;
    scanf("%d", &N);

    int *P = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &P[i]);
    }

    int *idorder = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        idorder[P[i]] = i;
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", idorder[i]);
    }

    free(P);
    free(idorder);

    return 0;
}

