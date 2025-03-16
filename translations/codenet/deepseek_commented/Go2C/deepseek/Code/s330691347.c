#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data represents a structure holding a string.
typedef struct {
    char *X;
} Data;

// Datas is a array of Data structures.
typedef Data Datas[100000];

// compare function for qsort
int compare(const void *a, const void *b) {
    Data *dataA = (Data *)a;
    Data *dataB = (Data *)b;
    return strcmp(dataA->X, dataB->X);
}

int main() {
    int N, L;
    scanf("%d %d", &N, &L);

    Datas s;
    for (int i = 0; i < N; i++) {
        s[i].X = (char *)malloc(L + 1);
        scanf("%s", s[i].X);
    }

    // Sort the array
    qsort(s, N, sizeof(Data), compare);

    // Concatenate the sorted strings
    char *ans = (char *)malloc(L * N + 1);
    ans[0] = '\0';
    for (int i = 0; i < N; i++) {
        strcat(ans, s[i].X);
    }

    // Print the result
    printf("%s\n", ans);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(s[i].X);
    }
    free(ans);

    return 0;
}
