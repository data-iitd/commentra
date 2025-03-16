
#include <stdio.h>
#include <string.h>

int main() {
    char str[100000]; // Declare a character array variable named'str' to store the input string

    // Read the input string from the standard input
    scanf("%s", str);

    int max = 0, cnt = 0; // Initialize two integer variables'max' and 'cnt' with zero values

    // Iterate through each character in the input string
    for (int i = 0; str[i]!= '\0'; i++) {
        // Check if the current character is a valid nucleotide (A, C, G or T)
        if (str[i] == 'A' || str[i] == 'C' || str[i] == 'G' || str[i] == 'T') {
            cnt++; // Increment the count if the character is a valid nucleotide
        } else { // Otherwise, reset the count to zero
            cnt = 0;
        }

        // Update the maximum count if the current count is greater than the previous maximum
        max = max < cnt? cnt : max;
    }

    // Print the maximum count of valid nucleotides found in the input string
    printf("%d\n", max);
}

