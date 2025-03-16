
#include <stdio.h>

int main() {
    // Initialize variables
    int N, K, R, S, P;
    char T[100001];

    // Read input from standard input
    scanf("%d %d %d %d %d", &N, &K, &R, &S, &P);
    scanf("%s", T);

    // Initialize dictionary to store the count of each character
    int dict[3] = {0};

    // Initialize boolean arrays to represent the state of each character
    char char;
    int s[100001] = {0};
    int r[100001] = {0};
    int p[100001] = {0};

    // Initialize all characters to be in the 'on' state
    for (int i = 0; i < N; i++) {
        s[i] = 1;
    }

    // Iterate through each character in the input string
    for (int i = 0; i < strlen(T); i++) {
        // Assign the current character to a variable
        char = T[i];

        // Check if we have reached the window size
        if (i >= K) {
            // If the current character is a substring of the previous K characters, toggle the state of the character
            if (char == T[i - K]) {
                switch (char) {
                    case's':
                        // Toggle the state of the character at index i%K
                        if (s[i % K]) {
                            s[i % K] = 0;
                            continue;
                        } else {
                            s[i % K] = 1;
                        }
                        break;
                    case 'r':
                        // Toggle the state of the character at index i%K
                        if (r[i % K]) {
                            r[i % K] = 0;
                            continue;
                        } else {
                            r[i % K] = 1;
                        }
                        break;
                    case 'p':
                        // Toggle the state of the character at index i%K
                        if (p[i % K]) {
                            p[i % K] = 0;
                            continue;
                        } else {
                            p[i % K] = 1;
                        }
                        break;
                }

            // If the current character is not a substring of the previous K characters, update the state of the characters accordingly
            } else {
                switch (char) {
                    case's':
                        // Set the state of the character at index i%K to 'on'
                        s[i % K] = 1;
                        break;
                    case 'r':
                        // Set the state of the character at index i%K to 'on'
                        r[i % K] = 1;
                        break;
                    case 'p':
                        // Set the state of the character at index i%K to 'on'
                        p[i % K] = 1;
                        break;
                }

            }
        }

        // Update the dictionary with the count of the current character
        switch (char) {
            case's':
                dict[0] = dict[0] + 1;
                break;
            case 'r':
                dict[1] = dict[1] + 1;
                break;
            case 'p':
                dict[2] = dict[2] + 1;
                break;
        }
    }

    // Calculate and print the result
    int res = P * dict[0] + S * dict[1] + R * dict[2];
    printf("%d\n", res);

    return 0;
}
