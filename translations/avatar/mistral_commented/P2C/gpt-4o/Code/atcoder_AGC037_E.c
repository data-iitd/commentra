#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100000

// Function to check if a substring is a normal dictionary
int check_normal_dict(char *u, int pointer1, int pointer2, int N) {
    for (int i = 0; i < N; i++) {
        if (u[pointer1 + i] > u[pointer2 + i]) {
            return 1; // True
        } else if (u[pointer1 + i] < u[pointer2 + i]) {
            return 0; // False
        }
    }
    return 0; // False
}

// Function to get the last dictionary of the string S
void get_last_dict(char *s_str, char *result, int N) {
    char U[MAX_LENGTH * 2];
    int len = strlen(s_str);
    
    // Create U by concatenating S with its reverse
    strcpy(U, s_str);
    for (int i = 0; i < len; i++) {
        U[len + i] = s_str[len - 1 - i];
    }
    U[len * 2] = '\0';

    char c = s_str[0]; // Find the minimum character in S
    int minindex = -1;

    // Find the index of the first occurrence of the minimum character in U
    for (int i = 0; i < len * 2; i++) {
        if (U[i] == c) {
            minindex = i;
            break;
        }
    }

    // Move the pointer p to the next character in U
    for (int p = minindex + 1; p <= len * 2; p++) {
        if (U[p] == c && check_normal_dict(U, minindex, p, N)) {
            minindex = p;
        }
    }

    // Return the substring starting from minindex and of length N
    strncpy(result, U + minindex, N);
    result[N] = '\0'; // Null-terminate the string
}

int main() {
    // Define input variables
    int N, K;
    scanf("%d %d", &N, &K);
    char S[MAX_LENGTH];
    scanf("%s", S);

    // Initialize a flag variable
    int aaaa = 0;

    // Check if K is greater than or equal to 15
    if (K >= 15) {
        aaaa = 1;
    } 
    // Else, check if 2^K is greater than or equal to N
    else if ((1 << K) >= N) {
        aaaa = 1;
    }

    // If the flag variable is True, print the result and exit the function
    if (aaaa) {
        for (int i = 0; i < N; i++) {
            putchar(min(S[0], S[0])); // Print the minimum character N times
        }
        putchar('\n');
        return 0;
    }

    // Get the last dictionary of the string S
    char last_dict[MAX_LENGTH];
    get_last_dict(S, last_dict, N);

    // If K is equal to 1, print the string S
    if (K == 1) {
        printf("%s\n", last_dict);
    } else {
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (last_dict[i] == last_dict[0]) {
                count++;
            } else {
                break;
            }
        }
        // If the count is greater than or equal to N/2^(K-1)
        if (count * (1 << (K - 1)) >= N) {
            for (int i = 0; i < N; i++) {
                putchar(last_dict[0]); // Print the first character N times
            }
            putchar('\n');
        } else {
            // Construct the string S
            for (int i = 0; i < count * (1 << (K - 1)) - 1; i++) {
                putchar(last_dict[0]); // Print the first character
            }
            printf("%s\n", last_dict); // Print the original string S
        }
    }

    return 0;
}

// <END-OF-CODE>
