#include <stdio.h>  // Including standard input/output library
#include <stdbool.h> // Including library for boolean type

#define MOD 1000000007 // Defining a constant MOD

int main() { // Main function
    int t; // Declaring an integer variable for the number of test cases
    scanf("%d", &t); // Reading the number of test cases

    while (t-- > 0) { // Starting a while loop that runs t times
        long n, a, b; // Declaring long variables for n, a, and b
        scanf("%ld %ld %ld", &n, &a, &b); // Reading the values of n, a, and b

        if (n < a) { // Checking if n is less than a
            printf("No\n"); // If true, printing "No" and continuing to the next test case
            continue; // Using the continue statement to skip the rest of the current iteration
        }

        if (a == b) { // Checking if a is equal to b
            if (n % a == 0) { // Checking if n is divisible by a
                printf("Yes\n"); // If true, printing "Yes"
            } else { // If false
                printf("No\n"); // Printing "No"
            }
            continue; // Using the continue statement to skip the rest of the current iteration
        }

        long x = b / (b - a); // Calculating the value of x
        if (n > x * a) { // Checking if n is greater than x * a
            printf("Yes\n"); // If true, printing "Yes" and continuing to the next test case
            continue; // Using the continue statement to skip the rest of the current iteration
        }

        long low = 1; // Initializing a long variable named low to 1
        long high = x + 1; // Initializing a long variable named high to x + 1
        long ans = 1; // Initializing a long variable named ans to 1

        while (low <= high) { // Starting a while loop that runs until low is less than or equal to high
            long mid = (low + high) / 2; // Calculating the middle value of low and high
            if (mid * a < n) { // Checking if mid * a is less than n
                low = mid + 1; // If true, setting low to mid + 1
            } else { // If false
                ans = mid; // Setting ans to mid
                high = mid - 1; // Setting high to mid - 1
            }
        }

        if (n > (ans - 1) * b && n < ans * a) { // Checking if n is between (ans - 1) * b and ans * a
            printf("No\n"); // If true, printing "No"
        } else { // If false
            printf("Yes\n"); // Printing "Yes"
        }
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
