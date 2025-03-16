#include <stdio.h>
#include <string.h>
#include <limits.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    char S[N + 1];
    scanf("%s", S);

    // Initialize a flag to determine if we can use a shortcut for output
    int aaaa = 0;

    // Check if K is large enough or if 2^K is greater than or equal to N
    if (K >= 15 || (1 << K) >= N) {
        aaaa = 1;
    }

    // If the shortcut condition is met, print the minimum character repeated N times and exit
    if (aaaa) {
        char minChar = S[0];
        for (int i = 1; i < N; i++) {
            if (S[i] < minChar) {
                minChar = S[i];
            }
        }
        for (int i = 0; i < N; i++) {
            printf("%c", minChar);
        }
        printf("\n");
        return 0;
    }

    // Function to get the lexicographically smallest rotation of the string
    char* get_last_dict(char* s_str) {
        // Create a doubled string to facilitate rotation comparison
        int len = strlen(s_str);
        char U[2 * len + 1];
        strcpy(U, s_str);
        strcat(U, s_str);

        // Find the minimum character in the original string
        char c = s_str[0];
        for (int i = 1; i < len; i++) {
            if (s_str[i] < c) {
                c = s_str[i];
            }
        }

        // Get the first occurrence of the minimum character
        char* p = strchr(U, c);
        int minindex = p - U;
        p += 1;

        // Iterate through the doubled string to find the smallest rotation
        while (p < U + 2 * len) {
            if (*p == c) {
                // Compare the current rotation with the previously found minimum
                if (check_normal_dict(U, minindex, p - U)) {
                    minindex = p - U;
                }
            }
            p += 1;
        }

        // Return the smallest rotation of length N
        char* result = (char*)malloc(N + 1);
        strncpy(result, U + minindex, N);
        result[N] = '\0';
        return result;
    }

    // Function to compare two rotations of the string
    int check_normal_dict(char* u, int pointer1, int pointer2) {
        for (int i = 0; i < N; i++) {
            if (u[pointer1 + i] > u[pointer2 + i]) {
                return 1;
            } else if (u[pointer1 + i] < u[pointer2 + i]) {
                return 0;
            }
        }
        return 0;
    }

    // Get the lexicographically smallest rotation of S
    char* S = get_last_dict(S);

    // If K is 1, simply print the smallest rotation
    if (K == 1) {
        printf("%s\n", S);
    } else {
        int count = 0;
        // Count how many times the first character appears consecutively
        for (int i = 0; i < N; i++) {
            if (S[i] == S[0]) {
                count += 1;
            } else {
                break;
            }
        }

        // Check if the repeated character can fill the string of length N
        if (count * (1 << (K - 1)) >= N) {
            for (int i = 0; i < N; i++) {
                printf("%c", S[0]);
            }
            printf("\n");
        } else {
            // Construct the output string based on the count and the original string
            char output[N + 1];
            for (int i = 0; i < count * ((1 << (K - 1)) - 1); i++) {
                output[i] = S[0];
            }
            strcpy(output + count * ((1 << (K - 1)) - 1), S);
            output[N] = '\0';
            printf("%s\n", output);
        }
    }

    free(S);
    return 0;
}
