
#include <stdio.h>
#include <string.h>

int main() {
    // Declare variables for input values
    int N, K, R, S, P;
    char T[100001];
    
    // Read input values: N (length of string), K (window size), R, S, P (points for each move)
    scanf("%d %d %d %d %d", &N, &K, &R, &S, &P);
    scanf("%s", T);

    // Initialize a dictionary to count occurrences of each move
    int dict[3] = {0}; // For 'r','s', 'p'
    char char;
    
    // Create slices to track the state of each move within the last K moves
    int s[100001] = {0}; // For's'
    int r[100001] = {0}; // For 'r'
    int p[100001] = {0}; // For 'p'
    
    // Initialize all moves as available (true)
    for (int i = 0; i < N; i++) {
        s[i] = 1;
    }
    memcpy(r, s, sizeof(s)); // Copy the initial state to r
    memcpy(p, s, sizeof(s)); // Copy the initial state to p
    
    // Iterate through each character in the input string T
    for (int i = 0; i < strlen(T); i++) {
        char = T[i]; // Get the current character

        // Check if we are within the bounds of K
        if (i >= K) {
            // If the current character is the same as the character K positions back
            if (char == T[i-K]) {
                // Toggle the availability of the move based on the current character
                switch (char) {
                    case's':
                        if (s[i%K]) {
                            s[i%K] = 0; // Mark's' as used
                            continue;
                        } else {
                            s[i%K] = 1; // Mark's' as available again
                        }
                        break;
                    case 'r':
                        if (r[i%K]) {
                            r[i%K] = 0; // Mark 'r' as used
                            continue;
                        } else {
                            r[i%K] = 1; // Mark 'r' as available again
                        }
                        break;
                    case 'p':
                        if (p[i%K]) {
                            p[i%K] = 0; // Mark 'p' as used
                            continue;
                        } else {
                            p[i%K] = 1; // Mark 'p' as available again
                        }
                        break;
                }
            } else {
                // If the current character is different from the character K positions back
                switch (char) {
                    case's':
                        s[i%K] = 1; // Mark's' as available
                        break;
                    case 'r':
                        r[i%K] = 1; // Mark 'r' as available
                        break;
                    case 'p':
                        p[i%K] = 1; // Mark 'p' as available
                        break;
                }
            }
        }

        // Count the occurrences of each move
        switch (char) {
            case's':
                dict[0] = dict[0] + 1; // Increment count for's'
                break;
            case 'r':
                dict[1] = dict[1] + 1; // Increment count for 'r'
                break;
            case 'p':
                dict[2] = dict[2] + 1; // Increment count for 'p'
                break;
        }
    }

    // Calculate the total score based on the counts and respective points
    int res = P*dict[1] + S*dict[2] + R*dict[0];
    
    // Print the final result
    printf("%d\n", res);
    
    return 0;
}
