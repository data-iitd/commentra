#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *differences = malloc(n * sizeof(int));
    int uniqueCount = 0;
    int foundNegative = 0;

    for (int i = 0; i < n; i++) {
        char s[100]; // Assuming the maximum length of the string is 100
        scanf("%s", s);

        int indexS = -1, indexG = -1;
        for (int j = 0; s[j] != '\0'; j++) {
            if (s[j] == 'S' && indexS == -1) {
                indexS = j;
            }
            if (s[j] == 'G' && indexG == -1) {
                indexG = j;
            }
        }

        int difference = indexS - indexG;
        if (difference < 0) {
            foundNegative = 1;
        } else {
            // Check if this difference is already counted
            int isUnique = 1;
            for (int k = 0; k < uniqueCount; k++) {
                if (differences[k] == difference) {
                    isUnique = 0;
                    break;
                }
            }
            if (isUnique) {
                differences[uniqueCount++] = difference;
            }
        }
    }

    if (foundNegative) {
        printf("-1\n");
    } else {
        printf("%d\n", uniqueCount);
    }

    free(differences);
    return 0;
}

// <END-OF-CODE>
