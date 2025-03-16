#include<stdio.h>
#include<math.h>

int main() {
    // Declare an integer N to store the number of elements
    int N = 0;
    
    // Read the number of elements from user input
    scanf("%d", &N);
    
    // Declare an array A of size N to hold the elements
    int A[N];
    
    // Read N elements into the array A
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    // Initialize m and M to the first element of the array A
    int m = A[0];
    int M = A[0];
    
    // Iterate through the array to find the minimum and maximum values
    for (int i = 0; i < N; i++) {
        // Update m if the current element is less than the current minimum
        if (A[i] < m) m = A[i];
        
        // Update M if the current element is greater than the current maximum
        if (A[i] > M) M = A[i];
    }

    // Output the difference between the maximum and minimum values
    printf("%d\n", M - m);

    // Return 0 to indicate successful execution
    return 0;
}

