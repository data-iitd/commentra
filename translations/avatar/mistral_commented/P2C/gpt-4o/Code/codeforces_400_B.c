#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_SET_SIZE 200

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize an array to store unique differences
    int differences[MAX_SET_SIZE];
    int diff_count = 0;

    // Read each string and calculate the differences
    for (int i = 0; i < n; i++) {
        char s[MAX_STR_LEN];
        scanf("%s", s);

        // Find indices of 'S' and 'G'
        char *ptr_S = strchr(s, 'S');
        char *ptr_G = strchr(s, 'G');

        int index_S = (ptr_S != NULL) ? (ptr_S - s) : -1;
        int index_G = (ptr_G != NULL) ? (ptr_G - s) : -1;

        // Calculate the difference
        int difference = index_S - index_G;

        // Check if the difference is already in the set
        int found = 0;
        for (int j = 0; j < diff_count; j++) {
            if (differences[j] == difference) {
                found = 1;
                break;
            }
        }

        // If not found, add to the set
        if (!found) {
            differences[diff_count++] = difference;
        }
    }

    // Check for any negative number in the set
    int has_negative = 0;
    for (int i = 0; i < diff_count; i++) {
        if (differences[i] < 0) {
            has_negative = 1;
            break;
        }
    }

    // Print the result
    if (has_negative) {
        printf("-1\n");
    } else {
        printf("%d\n", diff_count);
    }

    return 0;
}

// <END-OF-CODE>
