#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char arrs[n][100]; // Declare and initialize array to store strings
    for (int i = 0; i < n; i++) {
        scanf("%s", arrs[i]);
    }

    int length[n]; // Declare and initialize array to store differences
    int index = 0; // Initialize index for the length array
    int returnDex = 0; // Initialize returnDex to store the result

    for (int i = 0; i < n; i++) {
        char *tmp = arrs[i];
        char *dexG = strchr(tmp, 'G'); // Find the index of 'G' in the string
        char *dexS = strchr(tmp, 'S'); // Find the index of 'S' in the string
        if (dexG > dexS) { // Check if 'G' comes after 'S'
            returnDex = -1; // Set returnDex to -1 if 'G' is after 'S'
        }
        length[index++] = dexS - dexG; // Calculate and store the difference in length array
    }

    int set[n]; // Declare and initialize array to store unique differences
    int setIndex = 0; // Initialize setIndex for the set array
    int unique = 1; // Initialize unique to store the result

    for (int i = 0; i < n; i++) {
        int isUnique = 1;
        for (int j = 0; j < setIndex; j++) {
            if (length[i] == set[j]) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            set[setIndex++] = length[i];
        }
    }

    if (returnDex == -1) { // Check if returnDex is -1
        printf("%d\n", returnDex); // Print -1 if 'G' comes after 'S'
    } else {
        printf("%d\n", setIndex); // Print the size of the set array if 'G' does not come after 'S'
    }

    return 0;
}
