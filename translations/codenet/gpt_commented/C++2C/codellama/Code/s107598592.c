#include<stdio.h>
#include<stdlib.h>

int main() { 
    // Read the number of elements
    int N; 
    scanf("%d", &N);

    // Initialize two vectors to store the input values
    int *X = (int *)malloc(N * sizeof(int)); 
    int *Y = (int *)malloc(N * sizeof(int));
    
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
            printf("%d\n", Y[N/2]); // Output the upper median
        } else {
            printf("%d\n", Y[N/2 - 1]); // Output the lower median
        }
    }
    
    free(X);
    free(Y);
    return 0; // End of the program
}

int compare(const void *a, const void *b) {
    return ( *(int*)a - *(int*)b );
}

