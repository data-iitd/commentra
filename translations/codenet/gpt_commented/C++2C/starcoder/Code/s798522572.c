#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    // Declare variables for the number of elements (N) and a threshold (T)
    int N, T;
    
    // Read the number of elements and the threshold from input
    scanf("%d %d", &N, &T);
    
    // Initialize an array A to hold the input values
    int A[N];
    
    // Initialize a vector B to hold the transformed values
    int B[N];
    
    // Read N integers into the array A
    for(int i = 0; i < N; i++) 
        scanf("%d", &A[i]);
    
    // Initialize m with the first element of A
    int m = A[0];
    
    // Calculate the first element of B based on the first element of A and update m
    B[1] = A[1] - m;
    m = min(m, A[1]);
    
    // Loop through the remaining elements of A to fill B and update m
    for(int i = 2; i < N; i++){
        // Fill B[i] with the difference between A[i] and the minimum value found so far (m)
        B[i] = A[i] - m;
        
        // Update m to be the minimum of the current m and A[i]
        m = min(m, A[i]);
    }
    
    // Count and output the number of times the maximum element in B appears
    printf("%d\n", count(B, B+N, *max_element(B, B+N)));
}
