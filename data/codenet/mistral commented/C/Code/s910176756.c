#include<stdio.h> // Include the standard input/output library

int main(){ // Start of the main function
    int a, b, c; // Declare three integer variables: a, b, and c
    char op; // Declare a character variable: op

    scanf("%d %c %d", &a, &op, &b); // Read an integer, an operator, and another integer from the standard input

    while(1){ // Start of an infinite loop
        if ( op == '+' ){ // Check if the operator is '+'
            c = a + b; // If so, add the two numbers and store the result in variable c
            printf("%d\n",c); // Print the result to the standard output
        }

        else if ( op == '-' ){ // Check if the operator is '-'
            c = a - b; // If so, subtract the second number from the first and store the result in variable c
            printf("%d\n",c); // Print the result to the standard output
        }

        else if ( op == '*' ){ // Check if the operator is '*'
            c = a * b; // If so, multiply the two numbers and store the result in variable c
            printf("%d\n",c); // Print the result to the standard output
        }

        else if ( op == '/' ){ // Check if the operator is '/'
            c = a / b; // If so, divide the first number by the second and store the result in variable c
            printf("%d\n",c); // Print the result to the standard output
        }

        else { // If the operator is not one of the above, break the loop
            break;
        }

        scanf("%d %c %d", &a, &op, &b); // Read the next set of numbers and operator from the standard input
    }

    return 0; // End of the main function, return 0 to indicate successful execution
}
