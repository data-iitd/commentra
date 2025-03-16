#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// Define a structure to hold the maximum and minimum values
typedef struct {
    int max;
    int min;
} Pair;

// Function to read a line of input and return it as an array of integers
int* readLine() {
    int* arr = (int*)malloc(4 * sizeof(int));
    scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);
    return arr;
}

// Function to calculate the maximum value from the products of the pairs
int maxProduct(int a, int b, int c, int d) {
    int products[4] = {a * c, b * d, a * d, b * c};
    int max = products[0];
    for (int i = 1; i < 4; i++) {
        if (products[i] > max) {
            max = products[i];
        }
    }
    return max;
}

// Main function to execute the core logic of the program
int main() {
    // Read four integers from input
    int* numbers = readLine();
    int a = numbers[0];
    int b = numbers[1];
    int c = numbers[2];
    int d = numbers[3];
    
    // Calculate the maximum value from the products of the pairs and return it
    int result = maxProduct(a, b, c, d);
    
    // Print the result
    printf("%d\n", result);
    
    // Free the allocated memory
    free(numbers);
    
    return 0;
}

