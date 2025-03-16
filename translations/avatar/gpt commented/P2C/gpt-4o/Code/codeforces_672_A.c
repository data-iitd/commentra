#include <stdio.h>

int main() {
    // Initialize an array to store the results
    int li[1000]; // Assuming a maximum size of 1000 for simplicity
    int ind = 0;

    // Loop through numbers from 1 to 370
    for (int i = 1; i <= 370; i++) {
        // Initialize a temporary array to hold digits
        int temp[3]; // Maximum 3 digits for numbers up to 370
        int count = 0;
        int p = i, q = i;

        // Count the number of digits in the current number i
        while (p != 0) {
            p /= 10;  // Remove the last digit
            count++;  // Increment the digit count
        }

        // If the number has 1 digit, add it directly to the array
        if (count == 1) {
            li[ind++] = i;
        }

        // If the number has 2 digits
        if (count == 2) {
            int tempIndex = 0;  // Reset the temporary index
            // Extract digits of the number q
            while (q != 0) {
                temp[tempIndex++] = q % 10;  // Get the last digit
                q /= 10;  // Remove the last digit
            }
            // Add the digits in reverse order to the main array
            for (int j = tempIndex - 1; j >= 0; j--) {
                li[ind++] = temp[j];
            }
        }

        // If the number has 3 digits
        if (count == 3) {
            int tempIndex = 0;  // Reset the temporary index
            // Extract digits of the number q
            while (q != 0) {
                temp[tempIndex++] = q % 10;  // Get the last digit
                q /= 10;  // Remove the last digit
            }
            // Add the digits in reverse order to the main array
            for (int j = tempIndex - 1; j >= 0; j--) {
                li[ind++] = temp[j];
            }
        }
    }

    // Remove the last two elements from the array
    ind -= 2;

    // Take user input for the index
    int n;
    scanf("%d", &n);
    // Print the n-th element from the array (1-based index)
    printf("%d\n", li[n - 1]);

    return 0;
}

// <END-OF-CODE>
