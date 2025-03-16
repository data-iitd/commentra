
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
    // Initialize minimum value of array A to a large number
    int minA = pow(10,9) + 1;
    int num = 0;

    // Read number of elements and time t from the standard input
    int n, t;
    scanf("%d %d", &n, &t);

    // Create a vector A of size n to store the input elements
    int *A = (int *)malloc(n * sizeof(int));

    // Read each element of vector A from the standard input
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
        // Check if the current element is smaller than the minimum value
        if(minA > A[i]){
            // Update the minimum value of array A
            minA = A[i];
        }else{
            // Calculate the difference between the current element and the minimum value
            int diff = A[i] - minA;

            // If the difference is equal to the previous difference, increment the count of similar differences
            if(f == diff)num++;
            // If the difference is greater than the previous difference, reset the count to 1 and update the previous difference
            else if(f < diff){
                num = 1;
                f = diff;
            }
        }
    }

    // Print the count of similar differences on the standard output
    printf("%d\n", num);
}

