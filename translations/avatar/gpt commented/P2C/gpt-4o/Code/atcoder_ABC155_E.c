#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int main_b(char *s) {
    int pp = 0;  // Initialize the total score
    int na = 0;  // Initialize carry-over value
    int len = strlen(s);

    // Process the string in reverse order
    for (int i = len - 1; i >= 0; i--) {
        int c = s[i] - '0';  // Convert character to integer
        int cc = na + c;  // Calculate the current value with carry-over
        na = 0;  // Reset carry-over for the next iteration

        // Determine how to update the total score based on the current value
        if (cc <= 4) {
            pp += cc;  // If the value is 4 or less, add it directly to the score
        } else {
            na = 1;  // Set carry-over if the value exceeds 4
            if (i == len - 1) {
                pp += 1;  // If it's the last digit, add 1 to the score
            }
            pp += 10 - cc;  // Add the difference to the score
        }
    }

    printf("%d\n", pp);  // Output the final score
    return pp;
}

int main() {
    char s[1001];  // Buffer for input string
    scanf("%s", s);  // Read input string
    int pmin = 1000;  // Initialize minimum score for positive values
    int mmin = 0;  // Initialize minimum score for negative values
    char temp[1002];  // Buffer for modified string
    sprintf(temp, "0%s", s);  // Prepend '0' to the input string for easier processing

    // Process the string in reverse order
    for (int i = strlen(temp) - 1; i >= 0; i--) {
        int v = temp[i] - '0';  // Convert character to integer
        // Calculate new minimum scores based on current digit
        int npmin = (pmin + 10 - (v + 1) < mmin + 10 - v) ? (pmin + 10 - (v + 1)) : (mmin + 10 - v);
        int nmmin = (pmin + v + 1 < mmin + v) ? (pmin + v + 1) : (mmin + v);
        pmin = npmin;  // Update positive minimum score
        mmin = nmmin;  // Update negative minimum score
    }

    printf("%d\n", (pmin < mmin) ? pmin : mmin);  // Return the minimum score between positive and negative
    return 0;
}

// Note: The input method handling and clipboard functionality are omitted for simplicity.
// You can implement file reading or other input methods as needed.

