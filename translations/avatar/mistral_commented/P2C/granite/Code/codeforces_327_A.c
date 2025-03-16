
#include <stdio.h>
#include <string.h>

// Define a helper function 'find' to locate the indices of a character in a string
int find(char *s, char ch) {
    // Use a for loop to iterate through the string's' and count the occurrences of the character 'ch'
    int count = 0;
    for (int i = 0; s[i]!= '\0'; i++) {
        if (s[i] == ch) {
            count++;
        }
    }
    // Return the count of occurrences of the character 'ch' in the string's'
    return count;
}

int main() {
    // Read the number of test cases 'n' from the standard input
    int n;
    scanf("%d", &n);

    // Read the string's' from the standard input and remove any leading or trailing whitespaces
    char s[1000];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0;

    // Check if the string's' does not contain '0' character
    if (strchr(s, '0') == NULL) {
        // If '0' is not present, print the result as the number of test cases minus one
        printf("%d\n", n - 1);
    } else {
        // If '0' is present, proceed with further logic
        // Find the indices of '0' character in the string's'
        int indices[1000];
        int count = 0;
        for (int i = 0; s[i]!= '\0'; i++) {
            if (s[i] == '0') {
                indices[count++] = i;
            }
        }

        // Check if there is only one '0' character in the string's'
        if (count == 1) {
            // If there is only one '0', print the result as the number of '1's in the string
            printf("%d\n", n);
        } else {
            // If there are multiple '0's, calculate the maximum combination score
            int maximum = 0;

            // Generate all possible combinations of indices of '0' characters using nested for loops
            for (int i = 0; i < count; i++) {
                for (int j = i + 1; j < count; j++) {
                    // Calculate the score for the current combination using the given formula
                    int score = 2 + 2 * (abs(indices[i] - indices[j]) - 1) - (abs(i - j) - 1);
                    // Update the maximum combination score if the current combination score is greater
                    if (score > maximum) {
                        maximum = score;
                    }
                }
            }

            // Print the final result which is the number of '1's in the string plus the maximum combination score
            printf("%d\n", find(s, '1') + maximum);
        }
    }

    return 0;
}
