
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read the number of elements in the list from user input
    int n;
    scanf("%d", &n);

    // Create an empty dictionary's' with default value 0
    int *s = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        s[i] = 0;
    }

    // Create an empty list 'l' with length 'n' by reading elements from user input
    char **l = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        l[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", l[i]);
    }

    // Initialize a flag 'f' with value 'Yes'
    char *f = "Yes";

    // Iterate through each element 'v' in the list 'l'
    for (int i = 0; i < n; i++) {
        // Increment the count of 'v' in dictionary's'
        s[i] += 1;

        // Check if the count of 'v' in dictionary's' is greater than or equal to 2
        if (s[i] >= 2) {
            // If yes, set the flag 'f' to 'No'
            f = "No";
        }

        // Check if the index 'i' is not -1 and the last character of previous element is not equal to the current element
        if (i!= -1 && l[i][strlen(l[i]) - 1]!= l[i + 1][0]) {
            // If yes, set the flag 'f' to 'No'
            f = "No";
        }
    }

    // Print the final value of flag 'f'
    printf("%s\n", f);

    // Free the memory allocated for the list 'l' and the dictionary's'
    for (int i = 0; i < n; i++) {
        free(l[i]);
    }
    free(l);
    free(s);

    return 0;
}
