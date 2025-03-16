
#include <stdio.h> // Include the standard input/output library

int main() {
    // Reading an integer input from the user
    int x;
    scanf("%d", &x);
    
    // Using a ternary operator to determine the boolean value based on the input
    int bool = x == 1? 1 : 0;
    
    // Setting the result based on the boolean value; if bool is false, result is 1, otherwise 0
    int result =!bool? 1 : 0;
    
    // Printing the result to the console
    printf("%d", result);
    
    // Returning 0 to indicate successful execution of the program
    return 0;
}

