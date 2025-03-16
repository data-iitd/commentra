#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100000

int main() {
    // Initialize variables
    char s[MAX_LENGTH];
    
    // Read the input string
    scanf("%s", s);
    
    // Replace occurrences of "BC" with "D"
    char modified[MAX_LENGTH];
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'B' && s[i + 1] == 'C') {
            modified[j++] = 'D';
            i++; // Skip the next character
        } else {
            modified[j++] = s[i];
        }
    }
    modified[j] = '\0'; // Null-terminate the modified string

    // Initialize counters for 'A' and the result
    long long cnt = 0;
    long long tmp = 0;

    // Iterate through the modified string to count occurrences
    for (int i = 0; modified[i] != '\0'; i++) {
        // Increment temporary counter for 'A'
        if (modified[i] == 'A') {
            tmp++;
        }
        // Add the count of 'A's to the result when 'D' is encountered
        else if (modified[i] == 'D') {
            cnt += tmp;
        }
        // Reset the temporary counter for any other character
        else {
            tmp = 0;
        }
    }

    // Output the final count of valid pairs
    printf("%lld\n", cnt);

    return 0;
}

// <END-OF-CODE>
