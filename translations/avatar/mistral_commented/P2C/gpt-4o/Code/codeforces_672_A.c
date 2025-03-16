#include <stdio.h>

int main() {
    // Initialize an array 'li' to store the digits
    int li[1000]; // Assuming a maximum size of 1000 for simplicity
    int li_index = 0;

    // Iterate through the range from 1 to 370
    for (int i = 1; i <= 370; i++) {
        // Initialize a temporary array 'temp' to store digits
        int temp[3]; // Maximum 3 digits for numbers up to 370
        int temp_index = 0;

        // Assign current number 'i' to variables p and q
        int p = i, q = i;

        // Initialize a counter 'count' to keep track of number of digits
        int count = 0;

        // While p is not zero, divide it by 10 and increment the counter
        while (p != 0) {
            p /= 10;
            count++;
        }

        // Based on the number of digits, append the number or its digits to 'li'
        if (count == 1) {
            // If the number has only one digit, directly append it to 'li'
            li[li_index++] = i;
        } else {
            // If the number has two or three digits, extract its digits
            while (q != 0) {
                int x = q % 10;  // Get the last digit
                q /= 10;         // Move to the previous digit
                temp[temp_index++] = x;
            }
            // Append the reversed list to 'li'
            for (int j = temp_index - 1; j >= 0; j--) {
                li[li_index++] = temp[j];
            }
        }
    }

    // Remove the first two elements from 'li' as they are not required
    li_index -= 2;

    // Take an input 'n' from the user
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    // Print the required digit or digits from 'li' based on the user input
    printf("%d\n", li[n - 1]);

    return 0;
}
// <END-OF-CODE>
