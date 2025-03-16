#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char arrs[n][100]; // Assuming the maximum length of each string is 100
    for (int i = 0; i < n; i++) {
        scanf("%s", arrs[i]);
    }

    int length[n];
    int index = 0;
    int returnDex = 0;

    for (int i = 0; i < n; i++) {
        char *tmp = arrs[i];
        char *dexG = strchr(tmp, 'G'); // Find the index of 'G'
        char *dexS = strchr(tmp, 'S'); // Find the index of 'S'

        // If 'G' appears after 'S', set returnDex to -1
        if (dexG > dexS) {
            returnDex = -1;
        }

        // Calculate the length between 'G' and 'S' and store it in the length array
        length[index++] = dexS - dexG;
    }

    // Use a set to store unique lengths
    int *set = (int *)malloc(n * sizeof(int));
    int setSize = 0;

    // Add each length to the set to ensure uniqueness
    for (int i = 0; i < n; i++) {
        int unique = 1;
        for (int j = 0; j < setSize; j++) {
            if (set[j] == length[i]) {
                unique = 0;
                break;
            }
        }
        if (unique) {
            set[setSize++] = length[i];
        }
    }

    // Check if returnDex was set to -1 and print the appropriate result
    if (returnDex == -1) {
        printf("%d\n", returnDex); // Print -1 if 'G' is after 'S' in any string
    } else {
        printf("%d\n", setSize); // Print the number of unique lengths
    }

    free(set);
    return 0;
}
