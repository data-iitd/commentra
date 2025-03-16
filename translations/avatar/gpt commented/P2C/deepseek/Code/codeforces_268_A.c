#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LISTS 100
#define MAX_LEN 100

int main() {
    int n, count = 0;
    char *input = (char *)malloc(MAX_LEN * sizeof(char));
    char *token;
    char *lists[MAX_LISTS][MAX_LEN];
    int list_count = 0;

    // Read an integer input which represents the number of lists to be processed
    scanf("%d", &n);
    getchar(); // Consume the newline character after the integer input

    // Loop to read 'n' lines of input and store them in the list 'q'
    for (int i = 0; i < n; i++) {
        // Read a line of input
        fgets(input, MAX_LEN, stdin);
        input[strcspn(input, "\n")] = 0; // Remove the newline character

        // Split the input line into tokens and store them in the lists array
        token = strtok(input, " ");
        int token_count = 0;
        while (token != NULL) {
            lists[list_count][token_count] = token;
            token = strtok(NULL, " ");
            token_count++;
        }
        lists[list_count][token_count] = NULL; // Null-terminate the list
        list_count++;
    }

    // Nested loop to compare each list in 'q' with every other list
    for (int j = 0; j < list_count; j++) {
        for (int k = 0; k < list_count; k++) {
            // Skip comparison if both lists are the same
            if (j == k) continue;

            // Check if the first element of list 'j' matches the last element of list 'k'
            if (lists[j][0] != NULL && lists[k][strlen(lists[k]) - 1] != NULL && strcmp(lists[j][0], lists[k][strlen(lists[k]) - 1]) == 0) {
                // Increment the count if the condition is met
                count++;
            }
        }
    }

    // Print the final count of matching conditions
    printf("%d\n", count);

    // Free allocated memory
    free(input);

    return 0;
}
