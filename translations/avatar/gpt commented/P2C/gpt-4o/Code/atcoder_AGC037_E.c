#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100000

// Function to compare two rotations of the string
int check_normal_dict(char *u, int pointer1, int pointer2, int N) {
    for (int i = 0; i < N; i++) {
        if (u[pointer1 + i] > u[pointer2 + i]) {
            return 1; // pointer1 is greater
        } else if (u[pointer1 + i] < u[pointer2 + i]) {
            return 0; // pointer2 is greater
        }
    }
    return 0; // equal
}

// Function to get the lexicographically smallest rotation of the string
void get_last_dict(char *s_str, char *result, int N) {
    char U[MAX_LENGTH * 2];
    strcpy(U, s_str);
    strcat(U, strrev(strdup(s_str))); // Create a doubled string with reversed part

    char min_char = s_str[0];
    for (int i = 1; i < N; i++) {
        if (s_str[i] < min_char) {
            min_char = s_str[i];
        }
    }

    int p = 0;
    while (U[p] != min_char) {
        p++;
    }
    int minindex = p;
    p++;

    while (p <= N) {
        if (U[p] == min_char) {
            if (check_normal_dict(U, minindex, p, N)) {
                minindex = p;
            }
        }
        p++;
    }

    strncpy(result, U + minindex, N);
    result[N] = '\0'; // Null-terminate the result string
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    char S[MAX_LENGTH];
    scanf("%s", S);

    int aaaa = 0;

    // Check if K is large enough or if 2^K is greater than or equal to N
    if (K >= 15) {
        aaaa = 1;
    } else if ((1 << K) >= N) { // 2^K
        aaaa = 1;
    }

    // If the shortcut condition is met, print the minimum character repeated N times and exit
    if (aaaa) {
        char min_char = S[0];
        for (int i = 1; i < N; i++) {
            if (S[i] < min_char) {
                min_char = S[i];
            }
        }
        for (int i = 0; i < N; i++) {
            putchar(min_char);
        }
        putchar('\n');
        return 0;
    }

    char smallest_rotation[MAX_LENGTH];
    get_last_dict(S, smallest_rotation, N);

    // If K is 1, simply print the smallest rotation
    if (K == 1) {
        printf("%s\n", smallest_rotation);
    } else {
        int count = 0;
        // Count how many times the first character appears consecutively
        for (int i = 0; i < N; i++) {
            if (smallest_rotation[i] == smallest_rotation[0]) {
                count++;
            } else {
                break;
            }
        }

        // Check if the repeated character can fill the string of length N
        if (count * (1 << (K - 1)) >= N) { // 2^(K-1)
            for (int i = 0; i < N; i++) {
                putchar(smallest_rotation[0]);
            }
        } else {
            // Construct the output string based on the count and the original string
            for (int i = 0; i < count * ((1 << (K - 1)) - 1); i++) {
                putchar(smallest_rotation[0]);
            }
            printf("%s\n", smallest_rotation);
        }
    }

    return 0;
}

// Note: The strrev function is not standard in C. You may need to implement it or use an alternative method to reverse a string.
