#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M); // Reading the first two integers

    int *a = (int *)malloc(N * sizeof(int)); // Creating an array of size N to store integers

    // Initializing the array with zeros
    for (int i = 0; i < N; i++) {
        a[i] = 0;
    }

    // Reading the queries and updating the array accordingly
    for (int i = 0; i < M; i++) {
        int k;
        scanf("%d", &k); // Reading the number of elements to be updated

        for (int j = 0; j < k; j++) { // Iterating through the elements to be updated
            int s;
            scanf("%d", &s); // Reading the index of the element to be updated
            s--; // Decreasing the index by 1 as the array index starts from 0

            // Updating the value of the element at the given index
            a[s] |= (1 << i);
        }
    }

    int p = 0; // Initializing a variable to store the XOR of all given integers

    // Reading the integers and computing their XOR
    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x); // Reading an integer from the input
        p |= (x << i); // Computing the XOR of the current integer with the previous result
    }

    int ans = 0; // Initializing a variable to store the count of valid answers

    // Iterating through all possible combinations of the array elements
    for (int s = 0; s < (1 << N); s++) { // 1 << N represents 2^N
        int t = 0; // Initializing a variable to store the XOR of the current combination with the array elements

        // Computing the XOR of the current combination with the array elements
        for (int i = 0; i < N; i++) {
            if (((s >> i) & 1) == 1) { // Checking if the i-th bit of the current combination is set
                t ^= a[i]; // Updating the XOR of the current combination
            }
        }

        // Checking if the XOR of the current combination and the array elements is equal to the given integers
        if (p == t) {
            ans++; // Incrementing the count of valid answers
        }
    }

    printf("%d\n", ans); // Printing the count of valid answers
    free(a); // Freeing the allocated memory
    return 0; // Returning from main
}

// <END-OF-CODE>
