#include <stdio.h>

int main() {
    int n;  // Variable to store the input number
    long long factorial = 1;  // Initializing a variable to store the factorial result

    printf("Enter a number: ");  // Prompting the user for input
    scanf("%d", &n);  // Taking an integer input from the user

    for (int i = 1; i <= n; i++) {  // Starting a loop from 1 to the input number (inclusive)
        factorial *= i;  // Multiplying the factorial by the current number
    }

    printf("%lld\n", factorial);  // Printing the factorial result
    return 0;  // Indicating that the program ended successfully
}

// <END-OF-CODE>
