
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    fgets(input, 1000, stdin); // Read the first line of input (not used)
    fgets(input, 1000, stdin); // Read the second line of input which contains space-separated integers

    char *token = strtok(input, " ");
    int *numbers = (int *)malloc(sizeof(int) * 100);
    int i = 0;
    while (token!= NULL) {
        numbers[i++] = atoi(token);
        token = strtok(NULL, " ");
    }

    int sum = 0;
    for (int j = 0; j < i; j++) {
        for (int k = j + 1; k < i; k++) {
            sum += numbers[j] * numbers[k]; // Multiply the pair and add to sum
        }
    }

    printf("%d\n", sum); // Output the final sum of products

    free(numbers); // Free the allocated memory
    return 0;
}
