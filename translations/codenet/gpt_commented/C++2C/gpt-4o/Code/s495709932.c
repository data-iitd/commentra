#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

int main(void) {
    // Optimize input/output operations
<<<<<<< HEAD
    // Note: In C, we don't have ios::sync_with_stdio(false) equivalent

=======
    // Note: In C, we don't have the same optimization as in C++, but we can use buffered I/O if needed.
    
>>>>>>> 98c87cb78a (data updated)
    // Read the number of elements in the array
    int N;
    scanf("%d", &N);
    
    // Initialize an array to store the elements
    int64_t *A = (int64_t *)malloc(N * sizeof(int64_t));
    
    // Read the elements into the array
    rep(i, N) scanf("%lld", &A[i]);

    // Initialize a variable to keep track of the maximum difference
    int64_t answer = 0;
    
    // Iterate through all pairs of elements to find the maximum difference
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            // Calculate the absolute difference between the two elements
            int64_t diff = llabs(A[i] - A[j]);
            
            // Update the maximum difference found so far
            if (diff > answer) {
                answer = diff;
            }
        }
    }
    
    // Output the maximum difference
    printf("%lld\n", answer);
    
    // Free the allocated memory
    free(A);
    
    return 0;
}

// <END-OF-CODE>
