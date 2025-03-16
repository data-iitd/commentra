#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

int main() { 
    // Read the number of elements
    int N; 
    scanf("%d", &N);

    // Initialize two vectors to store the input values
    int X[N]; 
    int Y[N];
    
    // Read input values into vector X and copy them to vector Y
    for(int i = 0; i < N; i++) { 
        scanf("%d", &X[i]); 
        Y[i] = X[i]; 
    }
  
    // Sort vector Y to find the median
    qsort(Y, N, sizeof(int), compare);
  
    // Find the median value (middle element for odd N, or lower middle for even N)
    int y = Y[N/2];
    
    // Output the appropriate median value for each element in X
    for(int i = 0; i < N; i++) {
        // If the current element in X is less than the median
        if (X[i] < Y[N/2]) {
            printf("%d", Y[N/2]); // Output the upper median
        } else {
            printf("%d", Y[N/2 - 1]); // Output the lower median
        }
        printf("\n"); // Print a newline after each output
    }
    
    return 0; // End of the program
}

