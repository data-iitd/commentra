#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to get the lexicographically smallest rotation of the string
char* get_last_dict(char* s_str) {
    // Create a doubled string to facilitate rotation comparison
    char* U = (char*)malloc(2 * strlen(s_str) + 1);
    strcpy(U, s_str);
    strcat(U, s_str);
    U[2 * strlen(s_str)] = '\0';
    // Find the minimum character in the original string
    char c = *min_element(s_str, s_str + strlen(s_str));
    // Get the first occurrence of the minimum character
    int p = strchr(U, c) - U;
    int minindex = p;
    p += 1;
    
    // Iterate through the doubled string to find the smallest rotation
    while (p <= strlen(s_str)) {
        if (U[p] == c) {
            // Compare the current rotation with the previously found minimum
            if (check_normal_dict(U, minindex, p)) {
                minindex = p;
            }
        }
        p += 1;
    }
    
    // Return the smallest rotation of length N
    return U + minindex;
}

// Function to compare two rotations of the string
int check_normal_dict(char* u, int pointer1, int pointer2) {
    // Compare characters of the two rotations
    for (int i = 0; i < strlen(u); i++) {
        if (u[pointer1 + i] > u[pointer2 + i]) {
            return 1;
        } else if (u[pointer1 + i] < u[pointer2 + i]) {
            return 0;
        }
    }
    return 0;
}

int main() {
    // Read input values for N and K
    int N, K;
    scanf("%d %d", &N, &K);
    // Read the string S
    char* S = (char*)malloc(N + 1);
    scanf("%s", S);
    S[N] = '\0';

    // Initialize a flag to determine if we can use a shortcut for output
    int aaaa = 0;

    // Check if K is large enough or if 2^K is greater than or equal to N
    if (K >= 15) {
        aaaa = 1;
    } else if (1 << K >= N) {
        aaaa = 1;
    }

    // If the shortcut condition is met, print the minimum character repeated N times and exit
    if (aaaa) {
        printf("%c", *min_element(S, S + strlen(S)));
        for (int i = 1; i < N; i++) {
            printf("%c", *min_element(S, S + strlen(S)));
        }
        printf("\n");
        return 0;
    }

    // Get the lexicographically smallest rotation of S
    S = get_last_dict(S);

    // If K is 1, simply print the smallest rotation
    if (K == 1) {
        printf("%s\n", S);
    } else {
        int count = 0;
        // Count how many times the first character appears consecutively
        for (int i = 0; i < strlen(S); i++) {
            if (S[i] == S[0]) {
                count += 1;
            } else {
                break;
            }
        }
        
        // Check if the repeated character can fill the string of length N
        if (count * (1 << (K - 1)) >= N) {
            printf("%c", S[0]);
            for (int i = 1; i < N; i++) {
                printf("%c", S[0]);
            }
            printf("\n");
        } else {
            // Construct the output string based on the count and the original string
            char* S2 = (char*)malloc(N + 1);
            strcpy(S2, S);
            for (int i = 0; i < count * (1 << (K - 1)) - 1; i++) {
                strcat(S2, S);
            }
            // Print the first N characters of the constructed string
            printf("%s\n", S2);
        }
    }
    return 0;
}

