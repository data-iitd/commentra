#include <stdio.h> // Including standard input-output library
#include <stdbool.h> // Including library for boolean type

int main() { // Starting the main function
    int N; // Variable to store the number of elements in the array H
    long M; // Variable to store the number of queries

    scanf("%d", &N); // Reading the number of elements in the array H
    scanf("%ld", &M); // Reading the number of queries

    long H[N]; // Creating an array of size N to store the heights
    bool ans[N]; // Creating a boolean array of size N to store the answer for each index

    for (int i = 0; i < N; i++) { // Reading the elements of the array H
        scanf("%ld", &H[i]);
        ans[i] = true; // Initially assuming that all elements are in the left half
    }

    for (long query = 0; query < M; query++) { // Processing each query
        int temp1, temp2; // Variables to store the indices
        scanf("%d %d", &temp1, &temp2); // Reading the first and second indices

        if (H[temp1 - 1] < H[temp2 - 1]) { // If the height of the first index is less than the second index
            ans[temp1 - 1] = false; // The first index cannot be in the left half
        } else if (H[temp1 - 1] > H[temp2 - 1]) { // If the height of the first index is greater than the second index
            ans[temp2 - 1] = false; // The second index cannot be in the left half
        } else { // If the heights are equal
            ans[temp1 - 1] = false; // Both the first and second indices cannot be in the left half
            ans[temp2 - 1] = false;
        }
    }

    int ans2 = 0; // Initializing a counter to store the number of elements in the left half
    for (int i = 0; i < N; i++) { // Iterating through the array to find the number of elements in the left half
        if (ans[i]) { // If an element is still assumed to be in the left half
            ans2++; // Increment the counter
        }
    }

    printf("%d\n", ans2); // Printing the final answer
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
