

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, x;
    scanf("%d %d", &N, &x);

    int *sweet = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &sweet[i]);
    }

    qsort(sweet, N, sizeof(int), compare);

    int num = 0;
    for (int i = 0; i < N; i++) {
        if (x - sweet[i] >= 0) {
            x -= sweet[i];
            num++;
        } else {
            break;
        }
    }

    if (num == N && x > 0) {
        num--;
    }

    printf("%d\n", num);

    free(sweet);
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

