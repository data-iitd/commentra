#include <stdio.h>

int main() {
    // Declare variables to hold two integers and a character for the operation
    int a, b;
    char S;

    // Start an infinite loop to continuously accept user input
    while (1) {
        // Read two integers and an operator from the user
        scanf("%d %c %d", &a, &S, &b);

        // Perform addition if the operator is '+'
        if (S == '+') 
            printf("%d\n", a + b);

        // Perform subtraction if the operator is '-'
        if (S == '-') 
            printf("%d\n", a - b);

        // Perform multiplication if the operator is '*'
        if (S == '*') 
            printf("%d\n", a * b);

        // Perform division if the operator is '/'
        if (S == '/') 
            printf("%d\n", a / b);

        // Exit the loop if the operator is '?'
        if (S == '?') 
            break;
    }

    return 0;
}

// <END-OF-CODE>
