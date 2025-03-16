
#include<stdio.h>
#include<stdlib.h>

int main() { 
    // Read the number of elements
    int N; 
    scanf("%d", &N);

    // Initialize two arrays to store the input values
    int X[N]; 
    int Y[N];
    
    // Read input values into array X and copy them to array Y
    for(int i = 0; i < N; i++) { 
        scanf("%d", &X[i]); 
        Y[i] = X[i]; 
    }
  
    // Sort array Y to find the median
    qsort(Y, N, sizeof(int));
  
    // Find the median value (middle element for odd N, or lower middle for even N)
    int y = Y[N/2];
    
    // Output the appropriate median value for each element in X
    for(int i = 0; i < N; i++) {
        // If the current element in X is less than the median
        if (X[i] < Y[N/2]) {
            printf("%d\n", Y[N/2]); // Output the upper median
        } else {
            printf("%d\n", Y[N/2 - 1]); // Output the lower median
        }
    }
    
    return 0; // End of the program
}
