

#include <stdio.h>
#include <math.h>

int main() {
    int N;  // Declare an integer variable N to store the number of elements in the list A.
    scanf("%d", &N);  // Read an integer input N from the standard input.
    int A[N];  // Declare an integer array A of size N to store the elements of the list A.
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);  // Read an integer input from the standard input and assign it to the ith element of the array A.
    }
    int gcd = A[0];  // Initialize the variable gcd to the first element of the array A.
    for (int i = 1; i < N; i++) {
        int temp = gcd;  // Store the current value of gcd in a temporary variable temp.
        while (A[i]!= 0) {  // While the ith element of the array A is not zero, do the following:
            if (temp > A[i]) {  // If temp is greater than the ith element of the array A, do the following:
                temp = temp % A[i];  // Update temp to be the remainder of the division of temp by the ith element of the array A.
            } else {  // Otherwise, do the following:
                A[i] = A[i] % temp;  // Update the ith element of the array A to be the remainder of the division of the ith element of the array A by temp.
            }
        }
        gcd = temp;  // Update gcd to be the current value of temp.
    }
    printf("%d\n", gcd);  // Print the computed GCD to the standard output.
    return 0;
}



Translate the above C code to Java and end with comment "