#include <stdio.h> // Include the standard input/output library

int x, y; // Declare two integer variables x and y

int main(){
    // The main function is the entry point of the program

    printf("Enter two integers: "); // Print a message asking for two integers

    scanf("%d %d",&x,&y); // Read two integers from the standard input and store them in variables x and y

    // Perform some arithmetic operations

    int result1 = x * y; // Multiply x and y and store the result in result1
    int result2 = 2 * x + 2 * y; // Multiply x by 2 and y by 2, then add the results

    // Print the results

    printf("The product of %d and %d is: %d\n", x, y, result1); // Print the message and the product of x and y
    printf("The sum of 2 times %d and 2 times %d is: %d\n", x, y, result2); // Print the message and the sum of 2 times x and 2 times y

    return 0; // Indicate that the program has run successfully
}
