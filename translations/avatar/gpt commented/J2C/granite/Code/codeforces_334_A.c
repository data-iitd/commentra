
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object for input and a PrintWriter for output
    int n;
    scanf("%d", &n);
    int square = n * n;

    // Initialize arrays to hold odd and even numbers
    int odd[square];
    int even[square];
    int odd_count = 0;
    int even_count = 0;

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
    printf("div = %d\n", div);

    // Loop through the number of rows to print the pairs
    for (int i = 1; i <= loop; i++) {
        // For each row, print div pairs of numbers
        for (int j = 0; j < div; j++) {
            // Alternate between odd and even pairs based on the row number
            if (i % 2 == 1) {
                // For odd rows, print an odd number and the last even number
                printf("%d %d ", odd[--odd_count], even[even_count - 1]);
            } else {
                // For even rows, print an even number and the last odd number
                printf("%d %d ", even[--even_count], odd[odd_count - 1]);
            }
        }
        // Move to the next line after printing pairs for the current row
        printf("\n");
    }

    return 0;
}
