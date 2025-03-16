#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main() { 
    // Read a long integer N from user input
    long N; 
    scanf("%ld", &N); 
    
    // Initialize a variable to hold the minimum value
    long min = 0; 
    
    // Loop to read five long integers and find the minimum
    for (int i = 0; i < 5; i++) {
        // For the first iteration, directly assign the value to min
        if (i == 0) {
            scanf("%ld", &min); 
        } else {
            // For subsequent iterations, update min if a smaller value is found
            long temp; 
            scanf("%ld", &temp); 
            min = (temp < min) ? temp : min; 
        }
    }
    
    // Calculate the result by dividing N by min, rounding up, and adding 4
    long result = (long) ceil((double) N / min) + 4; 
    
    // Print the result
    printf("%ld\n", result); 
    
    return 0; 
}

