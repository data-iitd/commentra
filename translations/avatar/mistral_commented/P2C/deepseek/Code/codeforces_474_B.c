#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initialize an empty list `L`
    int *L = NULL;
    int size = 0;
    int r = 0;

    // Read the first input, which is the number of elements to add to the list
    scanf("%d", &size);

    // Allocate memory for the list `L`
    L = (int *)malloc(size * sizeof(int));
    if (L == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Use a for loop to iterate through each integer in the input
    char input[100];
    scanf("%s", input);
    char *token = strtok(input, " ");
    while (token != NULL) {
        // Add `r` elements to the list `L` with the value `r`
        int k = atoi(token);
        for (int i = 0; i < k; i++) {
            L[r] = r;
            r++;
        }
        token = strtok(NULL, " ");
    }

    // Read the second input, which represents the indices of the elements to print from the list
    int indices[100];
    int index_count = 0;
    scanf("%s", input);
    token = strtok(input, " ");
    while (token != NULL) {
        indices[index_count++] = atoi(token) - 1;
        token = strtok(NULL, " ");
    }

    // Use another for loop to iterate through each integer in the input
    for (int i = 0; i < index_count; i++) {
        // Print the element at the given index using the index as an offset from the beginning of the list
        printf("%d\n", L[indices[i]]);
    }

    // Free the allocated memory for the list `L`
    free(L);

    return 0;
}
