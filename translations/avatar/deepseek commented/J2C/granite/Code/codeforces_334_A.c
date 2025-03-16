
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, square, i, j, div, loop;
    scanf("%d", &n); // Read the size of the grid
    square = n * n; // Calculate the total number of elements
    int odd[square], even[square]; // Arrays to store odd and even numbers
    int odd_count = 0, even_count = 0; // Counters for odd and even numbers
    
    // Separating numbers into odd and even arrays
    for (i = 1; i <= square; i++) {
        if (i % 2 == 0) {
            even[even_count++] = i; // Add even numbers to the even array
        } else {
            odd[odd_count++] = i; // Add odd numbers to the odd array
        }
    }
    
    loop = square / n; // Calculate the number of rows/columns
    div = loop / 2; // Calculate half the number of elements in each row/column
    
    for (i = 1; i <= loop; i++) {
        for (j = 0; j < div; j++) {
            if (i % 2 == 1) {
                printf("%d %d ", odd[--odd_count], even[even_count++]); // Print odd and even numbers in reverse order for odd rows
            } else {
                printf("%d %d ", even[--even_count], odd[odd_count++]); // Print even and odd numbers in reverse order for even rows
            }
        }
        printf("\n"); // Move to the next line after each row
    }
    
    return 0;
}
// END-OF-CODE