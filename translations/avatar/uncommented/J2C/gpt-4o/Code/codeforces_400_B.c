#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    char arrs[MAX_N][100]; // Assuming max length of each string is 100
    for (int i = 0; i < n; i++) {
        scanf("%s", arrs[i]);
    }
    
    int length[MAX_N];
    int index = 0;
    int returnDex = 0;

    for (int i = 0; i < n; i++) {
        char *tmp = arrs[i];
        char *gPtr = strchr(tmp, 'G');
        char *sPtr = strchr(tmp, 'S');
        
        if (gPtr && sPtr) {
            int dexG = gPtr - tmp;
            int dexS = sPtr - tmp;
            if (dexG > dexS) {
                returnDex = -1;
            }
            length[index++] = dexS - dexG;
        }
    }

    // Using a simple method to count unique lengths
    int uniqueLengths[MAX_N] = {0};
    int uniqueCount = 0;

    for (int i = 0; i < index; i++) {
        int len = length[i];
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (uniqueLengths[j] == len) {
                found = 1;
                break;
            }
        }
        if (!found) {
            uniqueLengths[uniqueCount++] = len;
        }
    }

    if (returnDex == -1) {
        printf("%d\n", returnDex);
    } else {
        printf("%d\n", uniqueCount);
    }

    return 0;
}
