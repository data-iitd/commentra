#include <stdio.h>
#include <string.h>

int main() {
    // Initialize an empty string variable named S
    char S[100]; // Assuming a maximum length of 99 characters + 1 for null terminator

    // Read a string input from the user
    scanf("%s", S);

    // Initialize a variable i with value 2
    int i = 2;

    // Start a for loop that runs as long as i is less than or equal to the length of the string S
    while (i <= strlen(S)) {
        // Calculate the length of the string
        int lenS = strlen(S);
        
        // Check if the first half of the string S is equal to the second half of the string S
        if (strncmp(S, S + (lenS - i) / 2, (lenS - i) / 2) == 0) {
            // If the condition is true, print the length of the substring (len(S) - i)
            printf("%d\n", (lenS - i));
            break;
        }

        // Increment the value of i by 2
        i += 2;
    }

    return 0;
}

// <END-OF-CODE>
