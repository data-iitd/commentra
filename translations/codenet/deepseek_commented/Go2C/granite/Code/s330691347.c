
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *x;
} Data;

typedef struct {
    Data *p;
    int len;
} Datas;

int compare(const void *a, const void *b) {
    return strcmp(((Data *)a)->x, ((Data *)b)->x);
}

int main() {
    int N, L;
    scanf("%d %d", &N, &L);

    Datas s;
    s.len = N;
    s.p = (Data *)malloc(sizeof(Data) * N);

    for (int i = 0; i < N; i++) {
        s.p[i].x = (char *)malloc(sizeof(char) * L);
        scanf("%s", s.p[i].x);
    }

    qsort(s.p, N, sizeof(Data), compare);

    char *ans = (char *)malloc(sizeof(char) * (N * L + 1));
    ans[0] = '\0';

    for (int i = 0; i < N; i++) {
        strcat(ans, s.p[i].x);
    }

    printf("%s\n", ans);

    for (int i = 0; i < N; i++) {
        free(s.p[i].x);
    }
    free(s.p);
    free(ans);

    return 0;
}
