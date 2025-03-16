
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m, i, j, dexG, dexS, returnDex = 0;
    char **arrs;
    int *length;
    int index = 0;
    int *set;

    scanf("%d %d", &n, &m);
    arrs = (char **)malloc(n * sizeof(char *));
    length = (int *)malloc(n * sizeof(int));
    set = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        arrs[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", arrs[i]);
    }

    for (i = 0; i < n; i++) {
        dexG = strchr(arrs[i], 'G') - arrs[i];
        dexS = strchr(arrs[i], 'S') - arrs[i];
        if (dexG > dexS) {
            returnDex = -1;
        }
        length[index++] = dexS - dexG;
    }

    for (i = 0; i < n; i++) {
        set[i] = length[i];
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (set[i] == set[j]) {
                set[j] = -1;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (set[i] != -1) {
            printf("%d\n", set[i]);
        }
    }

    return 0;
}

