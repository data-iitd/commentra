#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, count = 0;
    scanf("%d", &n);
    char **q = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        q[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", q[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (q[i][0] == q[j][strlen(q[j]) - 1]) {
                count++;
            }
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < n; i++) {
        free(q[i]);
    }
    free(q);
    return 0;
}
