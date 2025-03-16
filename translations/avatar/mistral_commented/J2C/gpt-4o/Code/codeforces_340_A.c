#include <stdio.h>  // Including standard input-output library

int main() {  // Main function to start the program
    long x, y, a, b;  // Declaring variables for user input
    scanf("%ld %ld %ld %ld", &x, &y, &a, &b);  // Reading four long integer values from user input

    long j = 2, i, x1 = 0, y1 = 0, c = 0;  // Initializing variables
    int ans = 1;  // Initializing a boolean variable to keep track of the result

    c = (x > y) ? x : y;  // Finding the maximum value between x and y

    if (c > b) {  // Checking if the maximum value is greater than b
        printf("0\n");  // If true, printing 0 and setting ans to false
        ans = 0;
    }

    while (c % ((x < y) ? x : y) != 0 && ans) {  // Loop to find the greatest common divisor (GCD)
        if (x > y) {  // If x is greater than y
            c = x * j;  // Multiplying x by j and updating c
            j++;  // Incrementing j
        } else {
            c = y * j;  // Multiplying y by j and updating c
            j++;  // Incrementing j
        }

        if (c > b) {  // Checking if the current value of c is greater than b
            printf("0\n");  // If true, printing 0 and setting ans to false
            ans = 0;
            break;  // Exiting the loop
        }
    }

    if (ans) {  // If the GCD has been found
        long count = 0;  // Initializing a counter variable
        i = a;  // Starting the loop from a

        for (i = a; i <= b; i++) {  // Loop to find the number of times c divides i
            if (i % c == 0) break;  // If i is divisible by c, breaking the loop
        }

        if (i != b + 1) {  // Checking if the last number in the range is divisible by c
            printf("%ld\n", (b - i) / c + 1);  // Printing the result
        } else {
            printf("0\n");  // If the last number is not divisible by c, printing 0
        }
    }

    return 0;  // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
