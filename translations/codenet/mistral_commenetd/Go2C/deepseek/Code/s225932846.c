#include <stdio.h>
#include <string.h>

int main() {
    char S[100];
    int i = 2;

    // Read a string input from the user
    scanf("%s", S);

    // Start a while loop that runs as long as i is less than or equal to the length of the string S
    while (i <= strlen(S)) {

        // Check if the first half of the string S (from index 0 to (strlen(S)-i)/2) is equal to the second half of the string S (from index (strlen(S)-i)/2 to strlen(S)-i)
        if (strncmp(S, S + (strlen(S) - i) / 2, (strlen(S) - i) / 2) == 0) {

            // If the condition is true, print the length of the substring (strlen(S) - i) and break out of the loop
            printf("%lu\n", strlen(S) - i);
            break;
        }

        // Increment the value of i by 2
        i += 2;
    }

    return 0;
}
