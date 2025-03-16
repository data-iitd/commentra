
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

    Data *s = (Data *)malloc(sizeof(Data) * N);
    for (int i = 0; i < N; i++) {
        s[i].x = (char *)malloc(sizeof(char) * L);
        scanf("%s", s[i].x);
    }

    qsort(s, N, sizeof(Data), compare);

    for (int i = 0; i < N; i++) {
        printf("%s", s[i].x);
    }
    printf("\n");

    return 0;
}
