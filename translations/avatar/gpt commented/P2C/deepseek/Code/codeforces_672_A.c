#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize an empty list to store the results
    int li[370];
    // Initialize an index variable
    int ind = 0;

    // Loop through numbers from 1 to 370
    for (int i = 1; i <= 370; i++) {
        // Initialize a temporary list to hold digits
        int temp[10];
        // Assign the current number to p and q for processing
        int p = i, q = i;
        // Initialize a count variable to track the number of digits
        int count = 0;

        // Count the number of digits in the current number i
        while (p != 0) {
            p /= 10;  // Remove the last digit
            count++;  // Increment the digit count
        }

        // If the number has 1 digit, add it directly to the list
        if (count == 1) {
            li[ind++] = i;
        }

        // If the number has 2 digits
        if (count == 2) {
            int tempIndex = 0;
            // Extract digits of the number q
            while (q != 0) {
                int x = q % 10;  // Get the last digit
                q /= 10;  // Remove the last digit
                temp[tempIndex++] = x;  // Append the digit to the temporary list
            }
            // Add the digits in reverse order to the main list
            for (int j = tempIndex - 1; j >= 0; j--) {
                li[ind++] = temp[j];
            }
        }

        // If the number has 3 digits
        if (count == 3) {
            int tempIndex = 0;
            // Extract digits of the number q
            while (q != 0) {
                int x = q % 10;  // Get the last digit
                q /= 10;  // Remove the last digit
                temp[tempIndex++] = x;  // Append the digit to the temporary list
            }
            // Add the digits in reverse order to the main list
            for (int j = tempIndex - 1; j >= 0; j--) {
                li[ind++] = temp[j];
            }
        }
    }

    // Remove the last two elements from the list (not specified why)
    ind--;
    ind--;

    // Take user input for the index
    int n;
    printf("Enter the index: ");
    scanf("%d", &n);

    // Print the n-th element from the list (1-based index)
    printf("%d\n", li[n - 1]);

    return 0;
}
