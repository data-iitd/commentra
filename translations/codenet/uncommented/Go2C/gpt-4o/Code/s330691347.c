#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char X[100]; // Assuming a maximum length of 100 for each string
} Data;

int compare(const void *a, const void *b) {
    return strcmp(((Data *)a)->X, ((Data *)b)->X);
}

int main() {
    int N, L;
    scanf("%d %d", &N, &L);
    
    Data *s = malloc(N * sizeof(Data));
    
    for (int i = 0; i < N; i++) {
        scanf("%s", s[i].X);
    }

    // Sort the array of Data
    qsort(s, N, sizeof(Data), compare);

    // Concatenate the strings
    char ans[10000] = ""; // Assuming the total length won't exceed 10000
    for (int i = 0; i < N; i++) {
        strcat(ans, s[i].X);
    }

    printf("%s\n", ans);

    free(s);
    return 0;
}

// <END-OF-CODE>
