#include <stdio.h>
#include <string.h>

int main() {
    // Initialize variables
    int N, K, R, S, P;
    char T[100001]; // Assuming maximum length of T is 100000

    // Read input from standard input
    scanf("%d %d %d %d %d", &N, &K, &R, &S, &P);
    scanf("%s", T);

    // Initialize dictionary to store the count of each character
    int dict[3] = {0, 0, 0}; // dict[0] for 'r', dict[1] for 's', dict[2] for 'p'

    // Initialize boolean arrays to represent the state of each character
    int s[100001] = {0}; // State for 's'
    int r[100001] = {0}; // State for 'r'
    int p[100001] = {0}; // State for 'p'

    // Initialize all characters to be in the 'on' state
    for (int i = 0; i < N; i++) {
        s[i] = 1; // true
    }

    // Iterate through each character in the input string
    for (int i = 0; i < N; i++) {
        char char_current = T[i];

        // Check if we have reached the window size
        if (i >= K) {
            // If the current character is the same as the character K positions back
            if (char_current == T[i - K]) {
                switch (char_current) {
                    case 's':
                        s[i % K] = !s[i % K]; // Toggle state
                        continue;
                    case 'r':
                        r[i % K] = !r[i % K]; // Toggle state
                        continue;
                    case 'p':
                        p[i % K] = !p[i % K]; // Toggle state
                        continue;
                }
            } else {
                // If the current character is not the same as the character K positions back
                switch (char_current) {
                    case 's':
                        s[i % K] = 1; // Set state to 'on'
                        break;
                    case 'r':
                        r[i % K] = 1; // Set state to 'on'
                        break;
                    case 'p':
                        p[i % K] = 1; // Set state to 'on'
                        break;
                }
            }
        }

        // Update the dictionary with the count of the current character
        switch (char_current) {
            case 's':
                dict[1]++; // Increment count for 's'
                break;
            case 'r':
                dict[0]++; // Increment count for 'r'
                break;
            case 'p':
                dict[2]++; // Increment count for 'p'
                break;
        }
    }

    // Calculate and print the result
    int res = P * dict[0] + S * dict[2] + R * dict[1];
    printf("%d\n", res);

    return 0;
}

// <END-OF-CODE>
