#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double input, countOdd;
    char buffer[256];
    
    // Read a line of input and parse it as a double
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        input = atof(buffer);
        
        // Calculate the count of odd numbers based on the input
        countOdd = round(input / 2);
        
        // Print the result to the console
        printf("%.10f\n", countOdd / input);
    } else {
        // Handle input/output exceptions
        fprintf(stderr, "Input error\n");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
