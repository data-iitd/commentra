
#include<stdio.h>  // Include the standard input/output library for input and output operations
#include<math.h>    // Include the standard mathematical library for mathematical operations

int main() {
    int N = 0; // Declare an integer variable N and initialize it to 0
    scanf("%d", &N); // Read an integer value from the standard input and store it in N
    int A[N];  // Declare an array A of size N
    for (int i = 0; i < N; i++) scanf("%d", &A[i]); // Read N integers from the standard input and store them in the array A

    int m = A[0]; // Initialize the variable m to the first element of the array A
    int M = A[0]; // Initialize the variable M to the first element of the array A
    for (int i = 0; i < N; i++) { // Start a loop that iterates through the array A
        if (A[i] < m) m = A[i]; // If the current element is less than m, update m to the current element
        if (A[i] > M) M = A[i]; // If the current element is greater than M, update M to the current element
    }

    printf("%d\n", M - m); // Print the difference between the maximum and minimum values in the array A

    return 0; // Return 0 to indicate successful execution
}


