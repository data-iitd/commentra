#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    // Initialize the minimum value to a large number
    int minA = (int)pow(10,9) + 1;
    // Initialize the number of ways to achieve the maximum profit
    int num = 0;
    
    // Read the number of elements and an unused variable 't'
    int n, t, f = 0;
    scanf("%d %d", &n, &t);
    // Create an array to store the elements
    int *A = (int*)malloc(n * sizeof(int));
    
    // Read the elements into the array
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    
    // Iterate through the array to find the maximum profit
    for(int i = 0; i < n; i++){
        // Update the minimum value found so far
        if(minA > A[i]){
            minA = A[i];
        }else{
            // Check if the current profit is equal to the maximum profit found so far
            if(f == A[i] - minA) num++;
            // Update the maximum profit and reset the count if a new maximum is found
            else if(f < A[i] - minA){
                num = 1;
                f = A[i] - minA;
            }
        }
    }
    
    // Output the number of ways to achieve the maximum profit
    printf("%d\n", num);
    
    // Free the allocated memory
    free(A);
}
