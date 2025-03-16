#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    // Read a long integer N from user input
    long N = atol(gets(stdin)); 
    
    // Initialize a variable to hold the minimum value
    long min = 0; 
    
    // Loop to read five long integers and find the minimum
    for (int i = 0; i < 5; i++) {
        // For the first iteration, directly assign the value to min
        if (i == 0) {
            min = atol(gets(stdin)); 
        } else {
            // For subsequent iterations, update min if a smaller value is found
            min = (min < atol(gets(stdin)))? min : atol(gets(stdin)); 
        }
    }
    
    // Calculate the result by dividing N by min, rounding up, and adding 4
    printf("%ld\n", (long) ceil((double) N / min) + 4); 
    
    return 0;
}

