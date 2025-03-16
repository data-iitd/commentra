

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);  // Take the number of elements as input

    int S[n], R[n], H[n], C[n];  // Declare arrays to store the four integers for each element

    // Loop to take inputs and store them in the respective arrays
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &S[i], &R[i], &H[i], &C[i]);
    }

    int outdated[n];  // Declare an array to store outdated elements
    int outdated_count = 0;  // Initialize outdated_count to 0

    // Nested loop to compare each element with every other element
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (S[i] < S[j] && R[i] < R[j] && H[i] < H[j]) {
                outdated[outdated_count] = i;  // Store the index of outdated elements in outdated array
                outdated_count++;  // Increment outdated_count
            }
        }
    }

    int minimum_cost = 100000;  // Initialize minimum_cost to a large value
    int input_number = 0;  // Initialize input_number to 0

    // Iterate through the input_array to find the item with the minimum cost that is not outdated
    for (int i = 0; i < n; i++) {
        if (outdated_count == 0 || i!= outdated[0] && i!= outdated[1] && i!= outdated[2] && i!= outdated[3]) {
            if (C[i] < minimum_cost) {
                minimum_cost = C[i];  // Update minimum_cost
                input_number = i + 1;  // Update input_number
            }
        }
    }

    printf("%d", input_number);  // Print the input number of the item with the minimum cost that is not outdated

    return 0;
}
