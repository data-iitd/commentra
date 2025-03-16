#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char arrs[n][m+1];
    for (int i = 0; i < n; i++) {
        scanf("%s", arrs[i]);
    }
    int length[n];
    int index = 0;
    int returnDex = 0;
    for (int i = 0; i < n; i++) {
        char *tmp = arrs[i];
        int dexG = strchr(tmp, 'G') - tmp;
        int dexS = strchr(tmp, 'S') - tmp;
        if (dexG > dexS) {
            returnDex = -1;
        }
        length[index++] = dexS - dexG;
    }
    int *set = (int *)malloc(n * sizeof(int));
    int setSize = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < setSize; j++) {
            if (set[j] == length[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            set[setSize++] = length[i];
        }
    }
    if (returnDex == -1) {
        printf("%d\n", returnDex);
    } else {
        printf("%d\n", setSize);
    }
    free(set);
    return 0;
}
