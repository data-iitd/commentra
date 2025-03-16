#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n); // Read the size of the grid
    int square = n * n; // Calculate the total number of elements

    int *odd = (int *)malloc(square * sizeof(int)); // Array to store odd numbers
    int *even = (int *)malloc(square * sizeof(int)); // Array to store even numbers
    int oddCount = 0, evenCount = 0;

    // Separating numbers into odd and even arrays
    for (int i = 1; i <= square; i++) {
        if (i % 2 == 0) {
            even[evenCount++] = i; // Add even numbers to the even array
        } else {
            odd[oddCount++] = i; // Add odd numbers to the odd array
        }
    }

    int loop = square / n; // Calculate the number of rows/columns
    int div = loop / 2; // Calculate half the number of elements in each row/column

    // Debugging statement to print the value of div
    fprintf(stderr, "div: %d\n", div);

    // Nested loops to generate the pattern
    for (int i = 1; i <= loop; i++) {
        for (int j = 0; j < div; j++) {
            if (i % 2 == 1) {
                // Print odd and even numbers in reverse order for odd rows
                printf("%d %d ", odd[0], even[evenCount - 1]);
                // Remove the used numbers
                for (int k = 0; k < oddCount - 1; k++) {
                    odd[k] = odd[k + 1];
                }
                oddCount--;
                evenCount--;
            } else {
                // Print even and odd numbers in reverse order for even rows
                printf("%d %d ", even[0], odd[oddCount - 1]);
                // Remove the used numbers
                for (int k = 0; k < evenCount - 1; k++) {
                    even[k] = even[k + 1];
                }
                evenCount--;
                oddCount--;
            }
        }
        printf("\n"); // Move to the next line after each row
    }

    free(odd); // Free the allocated memory for odd numbers
    free(even); // Free the allocated memory for even numbers

    return 0;
}

// <END-OF-CODE>
