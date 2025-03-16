#include <stdio.h> // Including standard input-output library
#include <math.h>  // Including math library for sqrt function

int main() { // Starting the main function
    long n; // Declaring a long integer variable
    printf("Enter a number: "); // Prompting user for input
    if (scanf("%ld", &n) != 1) { // Reading a long integer value from user input
        printf("Error: Invalid input\n"); // Handling invalid input
        return 1; // Exiting with an error code
    }

    // Calculating the square root of the given number
    int sqrt_n = (int) sqrt(n); 

    // Initializing the answer variable to 0
    int answer = 0;

    // Checking for prime factors of the given number
    for (int i = 2; i <= sqrt_n; i++) { // Starting a for loop to check for prime factors
        int count = 0; // Initializing a counter variable to count the number of occurrences of a prime factor
        while (n % i == 0) { // Checking if the given number is divisible by the current prime factor
            n /= i; // Dividing the given number by the current prime factor
            count++; // Incrementing the counter variable
        }

        // Calculating the contribution of the current prime factor to the answer
        for (int j = 1; count - j >= 0; j++) {
            count -= j;
            answer++;
        }
    }

    // Checking for the remaining prime factor (if any)
    if (n > 1) {
        answer++;
    }

    // Printing the result
    printf("%d\n", answer); 

    return 0; // Exiting the program successfully
}

// <END-OF-CODE>
