#include <stdio.h>
#include <string.h>

int main() {
    int N, K, R, S, P;
    char T[100001];
    scanf("%d %d %d %d %d", &N, &K, &R, &S, &P);
    scanf("%s", T);

    // Initialize the dictionary to keep track of the counts of 'r', 's', and 'p'
    int dict[3] = {0, 0, 0};
    // Initialize a string to store the current character
    char char_current;
    // Initialize a boolean array to keep track of the availability of each choice for each player
    int s[100000];
    // Initialize all elements of the array to 1 (true)
    for (int i = 0; i < N; i++) {
        s[i] = 1;
    }

    // Iterate over each character in the string T
    for (int i = 0; i < N; i++) {
        char_current = T[i];
        // Check if the current index is greater than or equal to K
        if (i >= K) {
            // Check if the last K characters are the same as the current character
            if (char_current == T[i - K]) {
                // Update the availability of the choice based on the current character
                if (char_current == 's' && s[i % K] == 1) {
                    s[i % K] = 0;
                } else if (char_current == 's' && s[i % K] == 0) {
                    s[i % K] = 1;
                } else if (char_current == 'r' && s[i % K] == 1) {
                    s[i % K] = 0;
                } else if (char_current == 'r' && s[i % K] == 0) {
                    s[i % K] = 1;
                } else if (char_current == 'p' && s[i % K] == 1) {
                    s[i % K] = 0;
                } else if (char_current == 'p' && s[i % K] == 0) {
                    s[i % K] = 1;
                }
            } else {
                // Set the availability of the choice based on the current character
                if (char_current == 's') {
                    s[i % K] = 1;
                } else if (char_current == 'r') {
                    s[i % K] = 1;
                } else if (char_current == 'p') {
                    s[i % K] = 1;
                }
            }
        }
        // Update the counts in the dictionary based on the current character
        if (char_current == 's') {
            dict[0]++;
        } else if (char_current == 'r') {
            dict[1]++;
        } else if (char_current == 'p') {
            dict[2]++;
        }
    }

    // Calculate the result by multiplying the counts of 'r', 's', and 'p' with their respective values (P, S, R)
    int res = P * dict[1] + S * dict[2] + R * dict[0];
    // Print the result
    printf("%d\n", res);

    return 0;
}
