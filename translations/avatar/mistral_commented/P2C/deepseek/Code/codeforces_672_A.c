#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize an empty list 'li' to store the digits
    int li[370];
    int ind = 0;

    // Iterate through the range from 1 to 370
    for (int i = 1; i <= 370; i++) {
        // Initialize an empty list 'temp' to store digits
        int temp[3];
        int count = 0;

        // Assign current number 'i' to variables p and q
        int p = i, q = i;

        // While p is not zero, divide it by 10 and increment the counter
        while (p != 0) {
            p /= 10;
            count++;
        }

        // Based on the number of digits, append the number or its digits to 'li'
        if (count == 1) {
            // If the number has only one digit, directly append it to 'li'
            li[ind++] = i;
        } else if (count == 2) {
            // If the number has two digits, extract its digits and reverse the list
            int tempIndex = 0;
            while (q != 0) {
                temp[tempIndex++] = q % 10; // Get the last digit
                q /= 10; // Move to the previous digit
            }
            for (int j = tempIndex - 1; j >= 0; j--) {
                li[ind++] = temp[j]; // Append the reversed list to 'li'
            }
        } else if (count == 3) {
            // If the number has three digits, extract its digits and reverse the list
            int tempIndex = 0;
            while (q != 0) {
                temp[tempIndex++] = q % 10; // Get the last digit
                q /= 10; // Move to the previous digit
            }
            for (int j = tempIndex - 1; j >= 0; j--) {
                li[ind++] = temp[j]; // Append the reversed list to 'li'
            }
        }
    }

    // Remove the first two elements from 'li' as they are not required
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 370 - i - 1; j++) {
            li[j] = li[j + 1];
        }
    }

    // Take an input 'n' from the user
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    // Print the required digit or digits from 'li' based on the user input
    printf("%d\n", li[n - 1]);

    return 0;
}
