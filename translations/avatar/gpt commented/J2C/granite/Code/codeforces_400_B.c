
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Create a Scanner object to read input from the console
    // Read the number of strings (n) and the number of queries (m)
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize an array to store the strings
    char** arrs = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        arrs[i] = (char*)malloc(101 * sizeof(char));
        scanf("%s", arrs[i]);
    }

    // Initialize an array to store the lengths of segments between 'G' and 'S'
    int* length = (int*)malloc(n * sizeof(int));
    int index = 0;
    int returnDex = 0;

    // Iterate through each string to find the indices of 'G' and 'S'
    for (int i = 0; i < n; i++) {
        char* tmp = arrs[i];
        int dexG = -1;
        int dexS = -1;
        for (int j = 0; j < strlen(tmp); j++) {
            if (tmp[j] == 'G') {
                dexG = j;
            } else if (tmp[j] == 'S') {
                dexS = j;
            }
        }

        // If 'G' appears after 'S', set returnDex to -1
        if (dexG > dexS) {
            returnDex = -1;
        }

        // Calculate the length between 'G' and 'S' and store it in the length array
        length[index++] = dexS - dexG;
    }

    // Use a HashSet to store unique lengths
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

    // Check if returnDex was set to -1 and print the appropriate result
    if (returnDex == -1) {
        printf("%d\n", returnDex); // Print -1 if 'G' is after 'S' in any string
    } else {
        printf("%d\n", setSize); // Print the number of unique lengths
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(arrs[i]);
    }
    free(arrs);
    free(length);
    free(set);

    return 0;
}
