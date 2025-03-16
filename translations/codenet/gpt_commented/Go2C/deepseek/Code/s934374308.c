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
    int dict[3] = {0, 0, 0}; // [r, s, p]
    char char_now;
    
    // Create slices to track the state of each move within the last K moves
    int s[100000] = {0}; // For 's'
    int r[100000] = {0}; // For 'r'
    int p[100000] = {0}; // For 'p'
    
    // Iterate through each character in the input string T
    for (int i = 0; i < N; i++) {
        char_now = T[i]; // Get the current character

        // Check if we are within the bounds of K
        if (i >= K) {
            // If the current character is the same as the character K positions back
            if (char_now == T[i-K]) {
                // Toggle the availability of the move based on the current character
                if (char_now == 's') {
                    if (s[i % K] == 1) {
                        s[i % K] = 0; // Mark 's' as used
                        continue;
                    } else {
                        s[i % K] = 1; // Mark 's' as available again
                    }
                } else if (char_now == 'r') {
                    if (r[i % K] == 1) {
                        r[i % K] = 0; // Mark 'r' as used
                        continue;
                    } else {
                        r[i % K] = 1; // Mark 'r' as available again
                    }
                } else if (char_now == 'p') {
                    if (p[i % K] == 1) {
                        p[i % K] = 0; // Mark 'p' as used
                        continue;
                    } else {
                        p[i % K] = 1; // Mark 'p' as available again
                    }
                }
            } else {
                // If the current character is different from the character K positions back
                if (char_now == 's') {
                    s[i % K] = 1; // Mark 's' as available
                } else if (char_now == 'r') {
                    r[i % K] = 1; // Mark 'r' as available
                } else if (char_now == 'p') {
                    p[i % K] = 1; // Mark 'p' as available
                }
            }
        }

        // Count the occurrences of each move
        if (char_now == 's') {
            dict[0]++; // Increment count for 's'
        } else if (char_now == 'r') {
            dict[1]++; // Increment count for 'r'
        } else if (char_now == 'p') {
            dict[2]++; // Increment count for 'p'
        }
    }

    // Calculate the total score based on the counts and respective points
    int res = P * dict[1] + S * dict[2] + R * dict[0];
    
    // Print the final result
    printf("%d\n", res);

    return 0;
}
