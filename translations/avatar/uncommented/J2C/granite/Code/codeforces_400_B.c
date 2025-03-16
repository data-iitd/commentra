
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char** arrs = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        arrs[i] = (char*)malloc(m * sizeof(char));
        scanf("%s", arrs[i]);
    }
    int* length = (int*)malloc(n * sizeof(int));
    int index = 0;
    int returnDex = 0;
    for (int i = 0; i < n; i++) {
        char* tmp = arrs[i];
        int dexG = -1;
        int dexS = -1;
        for (int j = 0; j < m; j++) {
            if (tmp[j] == 'G') {
                dexG = j;
            }
            if (tmp[j] == 'S') {
                dexS = j;
            }
        }
        if (dexG > dexS) {
            returnDex = -1;
        }
        length[index++] = dexS - dexG;
    }
    int* set = (int*)malloc(n * sizeof(int));
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
    return 0;
}

