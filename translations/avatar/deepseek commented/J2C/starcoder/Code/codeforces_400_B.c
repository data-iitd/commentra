
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char arrs[n][1000];
    for (int i = 0; i < n; i++) {
        scanf("%s", arrs[i]);
    }
    int length[n];
    int index = 0;
    int returnDex = 0;
    for (int i = 0; i < n; i++) {
        int dexG = strstr(arrs[i], "G") - arrs[i];
        int dexS = strstr(arrs[i], "S") - arrs[i];
        if (dexG > dexS) {
            returnDex = -1;
        }
        length[index++] = dexS - dexG;
    }
    int set[1000];
    int setIndex = 0;
    for (int i = 0; i < n; i++) {
        int len = length[i];
        int found = 0;
        for (int j = 0; j < setIndex; j++) {
            if (set[j] == len) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            set[setIndex++] = len;
        }
    }
    if (returnDex == -1) {
        printf("%d\n", returnDex);
    } else {
        printf("%d\n", setIndex);
    }
    return 0;
}

