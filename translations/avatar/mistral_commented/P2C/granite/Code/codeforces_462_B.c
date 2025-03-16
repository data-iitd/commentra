
###
# Code
###

#include <stdio.h>
#include <string.h>

int main() {
    // Define input variables
    int n, k;
    scanf("%d %d", &n, &k);
    // n: number of characters in the string s
    // k: number of occurrences of a character we want to find

    char s[n];
    scanf("%s", s);
    // s: string to be processed

    // Initialize a list to store the count of each character
    int count[26] = {0};

    // Iterate through each character in the string s
    for (int i = 0; i < n; i++) {
        // Increment the count of the character in the list count
        count[s[i] - 'A']++;
    }

    // Sort the count list in descending order
    for (int i = 0; i < 25; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (count[i] < count[j]) {
                int temp = count[i];
                count[i] = count[j];
                count[j] = temp;
            }
        }
    }

    // Initialize result variable
    int res = 0;

    // Iterate through each character count in the list count
    for (int i = 0; i < 26; i++) {
        // Check if the count of the current character is greater than or equal to k
        if (count[i] >= k) {
            // Calculate the result and print it
            res += k * k;
            printf("%d\n", res);
            // Exit the loop as we have found the required characters
            break;
        }
        // Update the value of k by subtracting the count of the current character
        k -= count[i];
        // Add the square of the count of the current character to the result
        res += count[i] * count[i];
    }

    // Print the final result if no character is found with the required count
    printf("%d\n", res);

    return 0;
}
