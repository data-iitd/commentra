#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    // Declare variables to store input and intermediate results
    int n, x;

    // Read the value of n from standard input
    scanf("%d", &n);

    // Loop through numbers from 1 to n
    for(int i = 1; i <= n; i++) {
        // Initialize x with the current number i
        x = i;

        // Check if the number is divisible by 3 or ends with 3
        if(x % 3 == 0 || x % 10 == 3) {
            printf(" %d", i); // Output the number if the condition is met
            continue;
        } else {
            // Check each digit of the number to see if it contains 3
            int k = (int)log10(x); // Get the number of digits - 1
            while(k >= 0) {
                int j = (int)pow(10, k);
                if((x / j) % 10 == 3) {
                    printf(" %d", i); // Output the number if '3' is found in any digit
                    break;
                }
                k--;
            }
        }
    }

    // Output a newline character at the end of the program
    printf("\n");

    return 0;
}

// <END-OF-CODE>
