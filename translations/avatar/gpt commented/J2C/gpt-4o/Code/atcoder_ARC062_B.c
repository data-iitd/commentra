#include <stdio.h>
#include <string.h>

void solve(int testNumber, char *S) {
    int score = 0; // Initialize score to zero
    int length = strlen(S); // Get the length of the string S

    // Iterate through each character in the string S
    for (int i = 0; i < length; i++) {
        // Determine the character for 'my' based on the index (even or odd)
        char my = (i % 2 == 0) ? 'g' : 'p';

        // Get the character from the input string at the current index
        char his = S[i];

        // Compare 'my' and 'his' characters to update the score
        if (my != his) {
            // Increment score if 'my' is 'p', otherwise decrement
            score += (my == 'p') ? 1 : -1;
        }
    }

    // Output the final score
    printf("%d\n", score);
}

int main() {
    char S[100001]; // Assuming the maximum length of S is 100000

    // Read the input string S
    scanf("%s", S);

    // Call the solve function with test number and input string
    solve(1, S);

    return 0;
}

// <END-OF-CODE>
