#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    char *token;
    int *numbers;
    int n, sum = 0;

    // Read the first line of input (which we will ignore)
    fgets(input, sizeof(input), stdin);

    // Read the second line of input
    fgets(input, sizeof(input), stdin);

    // Tokenize the input string to get individual numbers
    token = strtok(input, " ");
    int count = 0;
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    // Allocate memory for the numbers array
    numbers = (int *)malloc(count * sizeof(int));
    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Reset the input string for re-reading
    rewind(stdin);
    fgets(input, sizeof(input), stdin);

    // Tokenize the input string again to get individual numbers
    token = strtok(input, " ");
    int index = 0;
    while (token != NULL) {
        numbers[index++] = atoi(token);
        token = strtok(NULL, " ");
    }

    // Calculate the sum of the products of all pairs of integers in the array
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            sum += numbers[i] * numbers[j];
        }
    }

    // Print the result
    printf("%d\n", sum);

    // Free the allocated memory
    free(numbers);

    return 0;
}
