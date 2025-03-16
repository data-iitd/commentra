#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char **s = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        s[i] = (char *)malloc((n + 1) * sizeof(char));
        scanf("%s", s[i]);
    }

    int flag = 0;
    int *d1 = (int *)malloc(n * sizeof(int));
    int *d2 = (int *)malloc(n * sizeof(int));
    int rem[100001] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                d1[i] = atoi(s[i] + j * 2);
            }
            if (i == n - j - 1) {
                d2[i] = atoi(s[i] + j * 2);
            }
            if (i != j && i != n - j - 1) {
                rem[atoi(s[i] + j * 2)]++;
            }
        }
    }

    if (rem[0] != n) {
        printf("NO\n");
        return 0;
    }

    if (memcmp(d1, d2, n * sizeof(int)) != 0) {
        printf("NO\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (d1[i] != d1[0]) {
            printf("NO\n");
            return 0;
        }
    }

    if (d1[0] == 0) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");

    for (int i = 0; i < n; i++) {
        free(s[i]);
    }
    free(s);
    free(d1);
    free(d2);

    return 0;
}
