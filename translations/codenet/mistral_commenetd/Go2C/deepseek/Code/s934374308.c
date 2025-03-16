#include <stdio.h>

int main() {
    int N, K, R, S, P;
    char T[100001];
    int dict[3] = {0, 0, 0}; // r, s, p
    int i;
    char char_now;
    int res = 0;

    // Read input from standard input
    scanf("%d %d %d %d %d", &N, &K, &R, &S, &P);
    scanf("%s", T);

    // Iterate through each character in the input string
    for (i = 0; i < N; i++) {
        char_now = T[i];

        // Update the dictionary with the count of the current character
        switch (char_now) {
            case 'r':
                dict[0]++;
                break;
            case 's':
                dict[1]++;
                break;
            case 'p':
                dict[2]++;
                break;
        }

        // Calculate the result
        if (i >= K) {
            if (T[i] == T[i - K]) {
                // If the current character is a substring of the previous K characters, do nothing
            } else {
                // If the current character is not a substring of the previous K characters, update the result
                switch (T[i]) {
                    case 'r':
                        res += P;
                        break;
                    case 's':
                        res += R;
                        break;
                    case 'p':
                        res += S;
                        break;
                }
            }
        } else {
            // If we haven't reached the window size, update the result
            switch (T[i]) {
                case 'r':
                    res += P;
                    break;
                case 's':
                    res += R;
                    break;
                case 'p':
                    res += S;
                    break;
            }
        }
    }

    // Print the result
    printf("%d\n", res);

    return 0;
}
