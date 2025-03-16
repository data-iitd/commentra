
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Read the number of strings to be processed
    int n;
    scanf("%d", &n);

    // Initialize a dictionary to count occurrences of each string
    int *s = (int *)malloc(n * sizeof(int));
    memset(s, 0, n * sizeof(int));

    // Read n strings into a list
    char **l = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        l[i] = (char *)malloc(101 * sizeof(char));
        scanf("%s", l[i]);
    }

    // Initialize a flag to determine if the conditions are met
    char *f = "Yes";

    // Initialize an index variable to track the previous string
    int i = -1;

    // Iterate through each string in the list
    for (int j = 0; j < n; j++) {
        // Increment the count for the current string
        s[j] += 1;

        // Check if the current string has appeared more than once
        if (s[j] >= 2) {
            f = "No";  // Set flag to 'No' if a duplicate is found
        }

        // Check if the previous string's last character does not match the current string's first character
        if (i!= -1 && l[i][strlen(l[i]) - 1]!= l[j][0]) {
            f = "No";  // Set flag to 'No' if the character condition is violated
        }

        // Update the index to the current string's index
        i = j;
    }

    // Print the final result based on the checks
    printf("%s\n", f);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(l[i]);
    }
    free(l);
    free(s);

    return 0;
}
