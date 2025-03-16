#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    scanf("%s", str);  // Read the input string from the standard input.

    int max = 0, cnt = 0;
    // Initialize max and cnt to keep track of the maximum length of consecutive 'A', 'C', 'G', or 'T' characters and the current length of such a sequence, respectively.

    for (int i = 0; i < strlen(str); i++) {
        // Iterate over each character in the string.
        if (str[i] == 'A' || str[i] == 'C' || str[i] == 'G' || str[i] == 'T') {
            // Check if the character is one of 'A', 'C', 'G', or 'T'.
            cnt++;  // If it is, increment the cnt variable.
        } else {
            cnt = 0;  // If not, reset cnt to 0.
        }
        max = max < cnt ? cnt : max;  // After each character, update max to be the maximum of max and cnt.
    }

    printf("%d\n", max);  // Print the value of max to the standard output.
}
