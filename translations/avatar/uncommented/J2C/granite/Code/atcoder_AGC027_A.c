
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, x;
    scanf("%d %d", &N, &x);
    int *sweet = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &sweet[i]);
    }
    qsort(sweet, N, sizeof(int), cmpfunc);
    int num = 0;
    for (int i = 0; i < N; i++) {
        if (x - sweet[num] >= 0) {
            x = x - sweet[num];
            num++;
        } else {
            break;
        }
    }
    if ((num == N) && (x > 0)) {
        num -= 1;
    }
    printf("%d\n", num);
    free(sweet);
    return 0;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

