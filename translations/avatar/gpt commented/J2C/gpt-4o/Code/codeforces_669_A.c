#include <stdio.h> // Including standard input/output library

int main() {
    int n; // Variable to store the input integer

    // Reading an integer input from the user
    scanf("%d", &n);
    
    // Calculating and printing the result based on the input integer n
    // The formula calculates (n / 3) * 2 and adds 1 if n is not divisible by 3
    printf("%d\n", (n / 3) * 2 + (n % 3 == 0 ? 0 : 1));

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
