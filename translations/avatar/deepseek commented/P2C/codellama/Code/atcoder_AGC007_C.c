#include <stdio.h>
#include <stdlib.h>

// Defining the main function to calculate a result based on N, d, and x
int main(int argc, char *argv[]) {
    // Reading the values of N, d, and x from standard input
    int N, d, x;
    scanf("%d %d %d", &N, &d, &x);
    
    // Initializing the result variable to accumulate the result
    int ret = 0;
    
    // Running the loop while N is greater than 0
    while (N > 0) {
        // Incrementing ret by the sum of d and (N - 0.5) * x
        ret += d + (N - 0.5) * x;
        
        // Updating the value of d using a complex formula
        d += d / N + 5 * x / (2 * N);
        
        // Updating the value of x using another formula
        x += 2 * x / N;
        
        // Decrementing N by 1
        N--;
    }
    
    // Printing the accumulated result
    printf("%d\n", ret);
    
    // Returning the accumulated result
    return ret;
}

