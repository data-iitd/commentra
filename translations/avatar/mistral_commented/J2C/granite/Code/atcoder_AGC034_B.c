

#include <stdio.h> // Standard input/output library
#include <string.h> // String manipulation library

int main() {
    char s[100001]; // Input string
    long long cnt = 0; // Counter for the number of "D"s
    long long tmp = 0; // Temporary variable for counting consecutive "A"s

    scanf("%s", s); // Read the input string

    for (int i = 0; s[i]!= '\0'; i++) {
        // Loop through each character in the string

        if (s[i] == 'A') {
            // If the character is "A", increment the temporary counter
            tmp++;
        } else if (s[i] == 'D') {
            // If the character is "D", add the temporary counter to the total count
            cnt += tmp;
        } else {
            // If the character is neither "A" nor "D", reset the temporary counter
            tmp = 0;
        }
    }

    // Print the result
    printf("%lld\n", cnt);

    return 0;
}

