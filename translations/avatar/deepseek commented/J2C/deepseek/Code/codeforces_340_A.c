#include <stdio.h>
#include <stdlib.h>

int main() {
    long x, y, a, b, j = 2, i, x1 = 0, y1 = 0, c = 0;
    int ans = 1;

    // Read input from the user
    scanf("%ld %ld %ld %ld", &x, &y, &a, &b);

    // Calculate the maximum of x and y and store it in c
    c = (x > y) ? x : y;

    // If c is greater than b, print "0" and set ans to 0
    if (c > b) {
        printf("0\n");
        ans = 0;
    }

    // Continue looping until c is divisible by the minimum of x and y or ans is 0
    while (c % ((x < y) ? x : y) != 0 && ans) {
        if (x > y) {
            c = x * j; // Update c to be x multiplied by j
        } else {
            c = y * j; // Update c to be y multiplied by j
        }
        j++; // Increment j

        // If the updated c is greater than b, print "0" and break out of the loop
        if (c > b) {
            printf("0\n");
            ans = 0;
            break;
        }
    }

    // If ans is still 1, calculate the number of multiples of c between a and b
    if (ans) {
        long count = 0;
        i = a;
        for (i = a; i <= b; i++) {
            if (i % c == 0) break; // Break if a multiple of c is found
        }
        if (i != b + 1) 
            printf("%ld\n", ((b - i) / c) + 1); // Print the number of multiples
        else 
            printf("0\n");
    }

    return 0;
}
