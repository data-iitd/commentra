#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read an integer n from input
    int n;
    scanf("%d", &n);
    
    // Calculate the square of n
    int square = n * n;
    
    // Allocate memory for odd and even numbers
    int *odd = (int *)malloc(square * sizeof(int));
    int *even = (int *)malloc(square * sizeof(int));
    int odd_count = 0, even_count = 0;
    
    // Populate the odd and even arrays with numbers from 1 to square
    for (int i = 1; i <= square; i++) {
        if (i % 2 == 0) {
            even[even_count++] = i; // Add to even array if the number is even
        } else {
            odd[odd_count++] = i; // Add to odd array if the number is odd
        }
    }
    
    // Calculate the number of loops and the division for pairing
    int loop = square / n;
    int div = loop / 2;
    
    // Debug output to check the value of div
    fprintf(stderr, "%d\n", div);
    
    // Loop through the number of rows to print the pairs
    for (int i = 1; i <= loop; i++) {
        // For each row, print div pairs of numbers
        for (int j = 0; j < div; j++) {
            // Alternate between odd and even pairs based on the row number
            if (i % 2 == 1) {
                // For odd rows, print an odd number and the last even number
                printf("%d %d ", odd[0], even[even_count - 1]);
                // Remove the used numbers
                for (int k = 0; k < odd_count - 1; k++) {
                    odd[k] = odd[k + 1];
                }
                odd_count--;
                even_count--;
            } else {
                // For even rows, print an even number and the last odd number
                printf("%d %d ", even[0], odd[odd_count - 1]);
                // Remove the used numbers
                for (int k = 0; k < even_count - 1; k++) {
                    even[k] = even[k + 1];
                }
                even_count--;
                odd_count--;
            }
        }
        // Move to the next line after printing pairs for the current row
        printf("\n");
    }
    
    // Free allocated memory
    free(odd);
    free(even);
    
    return 0;
}

// <END-OF-CODE>
