#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000
#define MAX_L 100

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char v[MAX_N][MAX_L];
    int N, L;

    scanf("%lld %lld", &N, &L);
    for (int i = 0; i < N; i++) {
        scanf("%s", v[i]);
    }

    qsort(v, N, sizeof(v[0]), compare);

    for (int i = 0; i < N; i++) {
        printf("%s", v[i]);
    }
    printf("\n");

    return 0;
}

<<<<<<< HEAD
// <END-OF-CODE>
=======
//<END-OF-CODE>
>>>>>>> 98c87cb78a (data updated)
