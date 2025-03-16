
#include <stdio.h>
#include <stdlib.h>

int main() {
    int li[370], ind, i, p, q, count, temp[3], x;

    // Initialize an empty list to store the results
    for (i = 0; i < 370; i++) {
        li[i] = 0;
    }

    // Initialize an index variable
    ind = 0;

    // Loop through numbers from 1 to 370
    for (i = 1; i <= 370; i++) {
        // Initialize a temporary list to hold digits
        for (int j = 0; j < 3; j++) {
            temp[j] = 0;
        }

        // Assign the current number to p and q for processing
        p = i;
        q = i;

        // Initialize a count variable to track the number of digits
        count = 0;

        // Count the number of digits in the current number i
        while (p!= 0) {
            p /= 10;  // Remove the last digit
            count++;  // Increment the digit count
        }

        // If the number has 1 digit, add it directly to the list
        if (count == 1) {
            li[ind] = i;
            ind++;
        }

        // If the number has 2 digits
        if (count == 2) {
            // Extract digits of the number q
            while (q!= 0) {
                x = q % 10;  // Get the last digit
                q /= 10;  // Remove the last digit
                temp[count - 1] = x;  // Append the digit to the temporary list
            }

            // Add the digits in reverse order to the main list
            li[ind] = temp[1];
            ind++;
            li[ind] = temp[0];
            ind++;
        }

        // If the number has 3 digits
        if (count == 3) {
            // Extract digits of the number q
            while (q!= 0) {
                x = q % 10;  // Get the last digit
                q /= 10;  // Remove the last digit
                temp[count - 1] = x;  // Append the digit to the temporary list
            }

            // Add the digits in reverse order to the main list
            li[ind] = temp[2];
            ind++;
            li[ind] = temp[1];
            ind++;
            li[ind] = temp[0];
            ind++;
        }
    }

    // Remove the last two elements from the list (not specified why)
    for (i = 0; i < 2; i++) {
        li[ind - 1] = 0;
        ind--;
    }

    // Take user input for the index
    int n;
    scanf("%d", &n);

    // Print the n-th element from the list (1-based index)
    printf("%d", li[n - 1]);

    return 0;
}
