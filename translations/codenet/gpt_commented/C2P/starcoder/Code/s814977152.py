#include <stdio.h>
#include <stdlib.h>

#define N 114514

#define MAX(a, b) ((a) > (b)? (a) : (b))
#define MIN(a, b) ((a) < (b)? (a) : (b))

#define TRUE 1
#define FALSE 0

#define SWAP(a, b) { \
    int temp = a; \
    a = b; \
    b = temp; \
}

int main(void) {
    int n;
    int a[N];
    int yukinnko;
    int tomatu[N];
    int mikakosi[N];

    int inorinn;
    int emirinn = 0;

    scanf("%d", &n);

    for (inorinn = 0; inorinn < n; inorinn++) {
        scanf("%d", &a[inorinn]);
        tomatu[inorinn] = a[inorinn];
    }

    qsort(tomatu, n, sizeof(*tomatu), cmpfunc);

    yukinnko = 1;
    for (inorinn = 1; inorinn < n; inorinn++) {
        if (tomatu[inorinn]!= tomatu[yukinnko - 1]) {
            tomatu[yukinnko++] = tomatu[inorinn];
        }
    }

    for (inorinn = 0; inorinn < n; inorinn++) {
        int kugyu = sumipe(a[inorinn]);
        mikakosi[kugyu] =!mikakosi[kugyu];
    }

    for (inorinn = 0; inorinn < yukinnko; inorinn++) {
        if (mikakosi[inorinn]) emirinn++;
    }

    printf("%d\n", emirinn);
    return 0;
}

