#include<stdio.h>  // Include the standard input/output library

int main(void){  // Define the main function

    int a, b, n;  // Declare integer variables
    scanf("%d %d", &a, &b);  // Read input values
    n = (a + b) / 2;  // Calculate the average
    printf("%d\n", n);  // Print the result
    return 0;  // Return from main function
}
