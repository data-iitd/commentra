#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int N, L;
    char **v;
    int i;

    scanf("%lld %lld", &N, &L);
    v = (char **)malloc(N * sizeof(char *));
    for (i = 0; i < N; i++) {
        v[i] = (char *)malloc((L + 1) * sizeof(char));
        scanf("%s", v[i]);
    }

    qsort(v, N, sizeof(char *), compare);

    for (i = 0; i < N; i++) {
        printf("%s", v[i]);
        if (i < N - 1) {
            printf("");
        }
    }
    printf("\n");

    for (i = 0; i < N; i++) {
        free(v[i]);
    }
    free(v);

    return 0;
}
