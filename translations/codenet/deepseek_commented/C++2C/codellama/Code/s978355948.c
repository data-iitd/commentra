#include <stdio.h>
#include <stdlib.h>

int main(){
    // Read the number of elements N and the maximum distance X
    int N, X;
    scanf("%d %d", &N, &X);
    
    // Read the lengths of the segments into a vector L
    int *L = (int *)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++)
        scanf("%d", &L[i]);
    
    // Initialize the index i and the distance d
    int i;
    int d = 0;
    
    // Loop through the segments to calculate the total distance
    for(i = 0; i < N; i++){
        // Add the current segment length to the total distance
        d = d + L[i];
        
        // If the total distance exceeds X, break the loop
        if(d > X)
            break;
    }

    // Output the number of segments used
    printf("%d\n", i+1);
    
    // Free the memory allocated for L
    free(L);
    
    // End of code
    printf("