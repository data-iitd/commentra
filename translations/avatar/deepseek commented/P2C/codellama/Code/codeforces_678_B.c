#include <stdio.h>
#include <stdlib.h>

int leapyear(int n) {  // Function to check if a year is a leap year
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0))
        return 1;
    else
        return 0;
}

int main() {
    int n, d = 0;  // Initialize the variable d to 0

    scanf("%d", &n);  // Take an integer input from the user

    // Determine if the year is a leap year and initialize ans accordingly
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0))
        ans = "ly";
    else
        ans = "nly";

    // Start an infinite loop to find the next Friday the 13th
    while (1) {
        if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {  // Check if n is a leap year
            if (d == 0) {  // Update d and n based on the current day
                d = 1;
                n += 1;
            }
            else if (d == 1) {
                d = 2;
                n += 1;
            }
            else if (d == 2) {
                d = 3;
                n += 1;
            }
            else if (d == 3) {
                d = 4;
                n += 1;
            }
            else if (d == 4) {
                d = 5;
                n += 1;
            }
            else if (d == 5) {
                d = 6;
                n += 1;
            }
            else if (d == 6) {
                d = 0;
                n += 1;
            }
        }
        else {
            if (d == 0) {
                d = 1;
                n += 1;
            }
            else if (d == 1) {
                d = 2;
                n += 1;
            }
            else if (d == 2) {
                d = 3;
                n += 1;
            }
            else if (d == 3) {
                d = 4;
                n += 1;
            }
            else if (d == 4) {
                d = 5;
                n += 1;
            }
            else if (d == 5) {
                d = 6;
                n += 1;
            }
            else if (d == 6) {
                d = 0;
                n += 1;
            }
        }

        // Check if the current day is Friday and the year is a leap year or not
        if (d == 4 && ans == "ly" && leapyear(n) == 1)
            break;  // Exit the loop if the condition is met
        else if (d == 4 && ans == "nly" && leapyear(n) == 0)
            break;  // Exit the loop if the condition is met
    }

    printf("%d", n);  // Print the final year after finding the next Friday the 13th

    return 0;
}

