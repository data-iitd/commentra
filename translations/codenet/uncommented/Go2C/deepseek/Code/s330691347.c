#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void out(char *x, ...) {
    // printf("%s\n", x);
}

typedef struct {
    char X[100];
} Data;

int compare(const void *a, const void *b) {
    Data *dataA = (Data *)a;
    Data *dataB = (Data *)b;
    return strcmp(dataA->X, dataB->X);
}

int main() {
    int N, L;
    scanf("%d %d", &N, &L);
    Data s[N];

    for (int i = 0; i < N; i++) {
        scanf("%s", s[i].X);
    }

    out("N", N, "L", L);
    qsort(s, N, sizeof(Data), compare);
    out("sorted", s);

    char ans[10000];
    ans[0] = '\0';
    for (int i = 0; i < N; i++) {
        strcat(ans, s[i].X);
    }
    printf("%s\n", ans);

    return 0;
}
