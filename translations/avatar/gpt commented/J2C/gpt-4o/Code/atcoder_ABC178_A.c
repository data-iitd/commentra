#include <stdio.h> // Including standard input and output library

int main() {
    // Declaring a variable to hold the input
    int x;
    
    // Reading an integer input from the user
    scanf("%d", &x);
    
    // Using a conditional operator to determine the boolean value based on the input
    int bool = (x == 1) ? 1 : 0;
    
    // Setting the result based on the boolean value; if bool is 0, result is 1, otherwise 0
    int result = (bool == 0) ? 1 : 0;
    
    // Printing the result to the console
    printf("%d\n", result);
    
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
