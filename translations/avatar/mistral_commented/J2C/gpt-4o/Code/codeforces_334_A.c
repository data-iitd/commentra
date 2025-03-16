#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);  // Reading the number 'n' from the user

    int square = n * n;  // Calculating the square of the number 'n'

    // Dynamically allocating memory for odd and even numbers
    int *odd = (int *)malloc(square * sizeof(int));
    int *even = (int *)malloc(square * sizeof(int));
    int odd_count = 0, even_count = 0;

    // Looping from 1 to square
    for (int i = 1; i <= square; i++) {
        if (i % 2 == 0) {  // If the number is even
            even[even_count++] = i;  // Add the number to the even array
        } else {  // If the number is odd
            odd[odd_count++] = i;  // Add the number to the odd array
        }
    }

    int loop = square / n;  // Calculating the number of pairs to be printed
    int div = loop / 2;  // Calculating half of the number of pairs

    // Looping through each pair
    for (int i = 1; i <= loop; i++) {
        for (int j = 0; j < div; j++) {  // Looping through half of the pair
            if (i % 2 == 1) {  // If the current pair is odd
                printf("%d %d ", odd[0], even[even_count - 1]);  // Print the first and last numbers of the current pair
                // Remove the first odd and last even
                for (int k = 0; k < odd_count - 1; k++) {
                    odd[k] = odd[k + 1];
                }
                odd_count--;
                even_count--;
            } else {  // If the current pair is even
                printf("%d %d ", even[0], odd[odd_count - 1]);  // Print the last and first numbers of the current pair
                // Remove the first even and last odd
                for (int k = 0; k < even_count - 1; k++) {
                    even[k] = even[k + 1];
                }
                even_count--;
                odd_count--;
            }
        }
        printf("\n");  // Printing a newline after each pair
    }

    // Freeing allocated memory
    free(odd);
    free(even);

    return 0;
}

// <END-OF-CODE>
