
#include <stdio.h>

int main() {
    int N, K, R, S, P;
    char T[100001];
    scanf("%d %d %d %d %d", &N, &K, &R, &S, &P);
    scanf("%s", T);

    // Initialize the dictionary to keep track of the counts of 'r','s', and 'p'
    int dict[3] = {0, 0, 0};
    // Initialize a string to store the current character
    char char = '\0';
    // Initialize a boolean slice to keep track of the availability of each choice for each player
    int s[100001] = {0};
    // Initialize all elements of the slice to true
    for (int i = 0; i < N; i++) {
        s[i] = 1;
    }
    // Create copies of the slice for 'r', 'p'
    int r[100001] = {0};
    int p[100001] = {0};
    for (int i = 0; i < N; i++) {
        r[i] = s[i];
        p[i] = s[i];
    }

    // Iterate over each character in the string T
    for (int i = 0; i < strlen(T); i++) {
        char = T[i];
        // Check if the current index is greater than or equal to K
        if (i >= K) {
            // Check if the last K characters are the same as the current character
            if (char == T[i - K]) {
                // Update the availability of the choice based on the current character
                switch (char) {
                    case's':
                        if (s[i % K]) {
                            s[i % K] = 0;
                            continue;
                        } else {
                            s[i % K] = 1;
                        }
                        break;
                    case 'r':
                        if (r[i % K]) {
                            r[i % K] = 0;
                            continue;
                        } else {
                            r[i % K] = 1;
                        }
                        break;
                    case 'p':
                        if (p[i % K]) {
                            p[i % K] = 0;
                            continue;
                        } else {
                            p[i % K] = 1;
                        }
                        break;
                }
            } else {
                // Set the availability of the choice based on the current character
                switch (char) {
                    case's':
                        s[i % K] = 1;
                        break;
                    case 'r':
                        r[i % K] = 1;
                        break;
                    case 'p':
                        p[i % K] = 1;
                        break;
                }
            }
        }
        // Update the counts in the dictionary based on the current character
        switch (char) {
            case's':
                dict[0]++;
                break;
            case 'r':
                dict[1]++;
                break;
            case 'p':
                dict[2]++;
                break;
        }
    }

    // Calculate the result by multiplying the counts of 'r','s', and 'p' with their respective values (P, S, R)
    int res = P * dict[0] + S * dict[1] + R * dict[2];
    // Print the result
    printf("%d\n", res);

    return 0;
}
