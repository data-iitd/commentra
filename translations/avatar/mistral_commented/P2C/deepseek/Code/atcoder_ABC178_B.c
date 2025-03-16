#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// Define constants
#define INF INT_MAX
#define MOD 1000000007
#define D_SIZE 4
#define D_DIM 2

// Function to read an integer list from standard input
int* read_ints() {
    int* arr = (int*)malloc(D_SIZE * sizeof(int));
    for (int i = 0; i < D_SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// Function to calculate the maximum product of pairs of numbers
int max_product(int a, int b, int c, int d) {
    int products[4] = {a * c, b * d, a * d, b * c};
    int max_val = products[0];
    for (int i = 1; i < 4; i++) {
        if (products[i] > max_val) {
            max_val = products[i];
        }
    }
    return max_val;
}

// Main function
int main() {
    // Read input values
    int* values = read_ints();
    int a = values[0];
    int b = values[1];
    int c = values[2];
    int d = values[3];

    // Calculate the maximum product of pairs of numbers
    int result = max_product(a, b, c, d);

    // Print the result
    printf("%d\n", result);

    // Free allocated memory
    free(values);

    return 0;
}
