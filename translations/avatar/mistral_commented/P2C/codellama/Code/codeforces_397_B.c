
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_T 100000
#define MAX_K 100000
#define MAX_N 100000

int main() {
    int t, n, k, i, j;
    int queries[MAX_T][3];
    char result[MAX_T][10];

    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        scanf("%d %d %d", &queries[i][0], &queries[i][1], &queries[i][2]);
        k = queries[i][0] / queries[i][1];
        if (k * queries[i][2] >= queries[i][0]) {
            strcpy(result[i], "Yes");
        } else {
            strcpy(result[i], "No");
        }
    }

    for (i = 0; i < t; i++) {
        printf("%s\n", result[i]);
    }

    return 0;
}

