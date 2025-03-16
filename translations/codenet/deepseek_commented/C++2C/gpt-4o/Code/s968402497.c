#include <stdio.h> // For standard input output operations
#include <stdlib.h> // For general purpose functions
#include <stdbool.h> // For using boolean type

#define mod 1000000007 // Define a constant for modular arithmetic
#define mod9 998244353 // Another constant for modular arithmetic
#define N 100007 // Define a constant for array sizes

int main() { // The main function
    int tc, n, m; // Declare variables for input values
    bool fl = false; // Declare a flag variable

    scanf("%d%d%d", &tc, &n, &m); // Read three integers from standard input
    if (n > m) { // Swap n and m if n is greater than m
        int temp = n;
        n = m;
        m = temp;
    }
    
    for (int i = 1; i <= m; i++) { // Iterate from 1 to m
        if (i * tc >= n && i * tc <= m) { // Check if the product of i and tc is between n and m
            printf("OK\n"); // Print "OK" if the condition is met
            fl = true; // Set the flag to true
            break; // Exit the loop
        }
    }
    
<<<<<<< HEAD
    if (!fl) { // Print "NG" if the flag is still false after the loop
        puts("NG");
    }
=======
    if (!fl) // Print "NG" if the flag is still false after the loop
        puts("NG");
>>>>>>> 98c87cb78a (data updated)
    
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
