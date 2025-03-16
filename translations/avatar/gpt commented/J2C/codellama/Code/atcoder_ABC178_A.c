#include <stdio.h>
#include <stdlib.h>

int main() {
    // Creating a Scanner object to read input from the console
    int x;
    scanf("%d", &x);
    
    // Using a ternary operator to determine the boolean value based on the input
    int bool = x == 1 ? 1 : 0;
    
    // Setting the result based on the boolean value; if bool is false, result is 1, otherwise 0
    int result = !bool ? 1 : 0;
    
    // Creating a PrintWriter object to output the result to the console
    printf("%d", result);
    
    // Flushing the output stream to ensure all data is written out
    fflush(stdout);
    
    // End of code
    return 0;
}


