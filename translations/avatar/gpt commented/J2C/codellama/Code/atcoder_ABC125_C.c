#include <stdio.h>
#include <stdlib.h>

// Array to hold the input integers
int *A;

int main() {
    // Create a Scanner object to read input from the console
    // Scanner sc = new Scanner(System.in);
    int N;
    scanf("%d", &N);
    
    // Initialize the array A with size N
    A = (int *)malloc(N * sizeof(int));
    
    // Read N integers from input and store them in array A
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    // Close the scanner to prevent resource leaks
    // sc.close();
    
    // Arrays to hold the GCD values from the left and right
    int *M = (int *)malloc(N * sizeof(int)); // Not used in the code, can be removed
    int *L = (int *)malloc(N * sizeof(int)); // GCD values from the left
    int *R = (int *)malloc(N * sizeof(int)); // GCD values from the right
    
    // Initialize the first element of L with the first element of A
    L[0] = A[0];
    
    // Calculate GCD from the left side
    for (int i = 1; i < N; i++) {
        L[i] = gcd(L[i - 1], A[i]);
    }
    
    // Initialize the last element of R with the last element of A
    R[N - 1] = A[N - 1];
    
    // Calculate GCD from the right side
    for (int i = N - 2; i >= 0; i--) {
        R[i] = gcd(R[i + 1], A[i]);
    }
    
    // Calculate the maximum GCD excluding the last element
    int answer = max(L[N - 2], R[1]);
    
    // Iterate through the array to find the maximum GCD excluding the current element
    for (int i = 1; i < N - 1; i++) {
        answer = max(answer, gcd(L[i - 1], R[i + 1]));
    }
    
    // Print the final answer
    printf("%d\n", answer);
    
    // Free the memory allocated for the arrays
    free(A);
    free(M);
    free(L);
    free(R);
    
    return 0;
}

// Method to calculate the GCD of two integers using the Euclidean algorithm
int gcd(int a, int b) {
    int tmp;
    
    // Ensure a is greater than or equal to b
    if (b > a) {
        tmp = a;
        a = b;
        b = tmp;
    }
    
    // If b is zero, return a as the GCD
    if (b == 0) {
        return a;
    }
    
    // Calculate GCD using the Euclidean algorithm
    int r = -1;
    do {
        r = a % b;
        a = b;
        b = r;
    } while (r != 0);
    
    // Return the GCD
    return a;
}

// Method to calculate the maximum of two integers
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

