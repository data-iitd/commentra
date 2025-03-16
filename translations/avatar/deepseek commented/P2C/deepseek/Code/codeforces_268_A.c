#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, count = 0;
    scanf("%d", &n);  // Take an integer input representing the number of elements
    char **q = (char **)malloc(n * sizeof(char *));  // Initialize a pointer to an array of strings

    // Loop to take input and append to the list `q`
    for (int i = 0; i < n; i++) {
        q[i] = (char *)malloc(100 * sizeof(char));  // Allocate memory for each string
        scanf("%s", q[i]);  // Read the string input
    }

    // Nested loop to compare each element with every other element
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            if (j == k)  // Skip if the same element is compared with itself
                continue;
            else if (q[j][0] == q[k][strlen(q[k]) - 1])  // Check if the first character of `j` matches the last character of `k`
                count++;  // Increment the counter if the condition is met
        }
    }

    printf("%d\n", count);  // Print the total count of valid pairs

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(q[i]);
    }
    free(q);

    return 0;
}
