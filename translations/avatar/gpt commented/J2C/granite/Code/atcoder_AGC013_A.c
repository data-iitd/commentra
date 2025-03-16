
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N); // Read the number of elements N from user input
    
    int A[N]; // Initialize an array A of size N to store the input integers
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]); // Read N integers from user input and store them in array A
    }
    
    int count = 0; // Initialize a counter to keep track of the number of segments
    
    for (int i = 0; i < N; i++) {
        if (i == N - 1) {
            count++; // If we are at the last element, increment the count
        } else if (A[i] == A[i + 1]) {
            // Do nothing, just continue
        } else if (A[i] < A[i + 1]) {
            while (A[i] <= A[i + 1]) {
                i++; // Move to the next element
                if (i == N - 1) break; // Break if we reach the end of the array
            }
            count++; // Increment the count for the found segment
        } else {
            while (A[i] >= A[i + 1]) {
                i++; // Move to the next element
                if (i == N - 1) break; // Break if we reach the end of the array
            }
            count++; // Increment the count for the found segment
        }
    }
    
    printf("%d\n", count); // Output the total number of segments found
    
    return 0;
}
