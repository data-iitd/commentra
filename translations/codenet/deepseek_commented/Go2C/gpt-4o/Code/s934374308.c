#include <stdio.h>
#include <string.h>

int main() {
    int N, K, R, S, P;
    char T[100001]; // Assuming T can be up to 100000 characters
    scanf("%d %d %d %d %d", &N, &K, &R, &S, &P);
    scanf("%s", T);

    // Initialize the dictionary to keep track of the counts of 'r', 's', and 'p'
    int dict[3] = {0, 0, 0}; // dict[0] for 'r', dict[1] for 's', dict[2] for 'p'
    // Initialize a boolean array to keep track of the availability of each choice for each player
    int s[100001] = {1}; // Initialize all elements to true
    int r[100001] = {1}; // Initialize all elements to true
    int p[100001] = {1}; // Initialize all elements to true

    // Iterate over each character in the string T
    for (int i = 0; i < N; i++) {
        char char_current = T[i];
        // Check if the current index is greater than or equal to K
        if (i >= K) {
            // Check if the last K characters are the same as the current character
            if (char_current == T[i - K]) {
                // Update the availability of the choice based on the current character
                switch (char_current) {
                    case 's':
                        if (s[i % K]) {
                            s[i % K] = 0; // Set to false
                            continue;
                        } else {
                            s[i % K] = 1; // Set to true
                        }
                        break;
                    case 'r':
                        if (r[i % K]) {
                            r[i % K] = 0; // Set to false
                            continue;
                        } else {
                            r[i % K] = 1; // Set to true
                        }
                        break;
                    case 'p':
                        if (p[i % K]) {
                            p[i % K] = 0; // Set to false
                            continue;
                        } else {
                            p[i % K] = 1; // Set to true
                        }
                        break;
                }
            } else {
                // Set the availability of the choice based on the current character
                switch (char_current) {
                    case 's':
                        s[i % K] = 1; // Set to true
                        break;
                    case 'r':
                        r[i % K] = 1; // Set to true
                        break;
                    case 'p':
                        p[i % K] = 1; // Set to true
                        break;
                }
            }
        }
        // Update the counts in the dictionary based on the current character
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

    // Calculate the result by multiplying the counts of 'r', 's', and 'p' with their respective values (P, S, R)
    int res = P * dict[0] + S * dict[1] + R * dict[2];
    // Print the result
    printf("%d\n", res);

    return 0;
}

// <END-OF-CODE>
