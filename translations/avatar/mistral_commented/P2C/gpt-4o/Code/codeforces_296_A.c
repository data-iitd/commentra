#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Take an integer 'n' as input from the user
    int n;
    scanf("%d", &n);

    // Take a list 'm' as input from the user
    char m[100]; // Assuming a maximum of 100 characters
    scanf("%s", m);

    // Initialize a boolean variable 'possible' with a default value of 1 (true)
    int possible = 1;

    // Create an array to count occurrences of each character (assuming ASCII)
    int count[256] = {0};

    // Count occurrences of each character in the list 'm'
    for (int j = 0; j < strlen(m); j++) {
        count[(unsigned char)m[j]]++;
    }

    // Iterate through each unique character
    for (int i = 0; i < 256; i++) {
        // Check if the character appears more than 'n/2 + 1' times
        if (count[i] >= n / 2 + 1) {
            // If the condition is true, set 'possible' to 0 (false) and break the loop
            possible = 0;
            break;
        }
    }

    // Print 'YES' if 'possible' is still true, otherwise print 'NO'
    printf("%s\n", possible ? "YES" : "NO");

    return 0;
}

// <END-OF-CODE>
