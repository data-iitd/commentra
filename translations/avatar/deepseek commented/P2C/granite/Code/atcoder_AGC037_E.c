

#include <stdio.h>
#include <string.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    // Read the values of N and K from input
    char S[100001];
    scanf("%s", S);
    // Read the string S from input
    int aaaa = 0;
    // Initialize a flag to check special conditions
    if (K >= 15) {
        aaaa = 1;
        // If K is 15 or more, set the flag to 1
    } else if (1 << K >= N) {
        aaaa = 1;
        // If 2 to the power of K is greater than or equal to N, set the flag to 1
    }
    if (aaaa) {
        printf("%c", *min(S, S + N));
        for (int i = 1; i < N; i++) {
            printf("%c", *(min(S, S + N)));
        }
        printf("\n");
        return 0;
        // If the flag is 1, print the minimum character in S repeated N times and end the program
    }
    char U[200001];
    strcpy(U, S);
    strcat(U, S);
    // Concatenate the string with its reverse
    char c = *min(S, S + N);
    // Find the minimum character in the original string
    int p = 0;
    while (U[p]!= c) {
        p++;
    }
    // Find the index of the minimum character in the concatenated string
    int minindex = p;
    p++;
    while (p <= N) {
        if (U[p] == c) {
            if (check_normal_dict(U, minindex, p)) {
                minindex = p;
            }
        }
        p++;
    }
    for (int i = 0; i < N; i++) {
        printf("%c", U[minindex + i]);
    }
    printf("\n");
    // Find the lexicographically smallest substring of length N and print it
    return 0;
    // End the program
}

char* get_last_dict(char* s_str) {
    char U[200001];
    strcpy(U, s_str);
    strcat(U, s_str);
    // Concatenate the string with its reverse
    char c = *min(s_str, s_str + N);
    // Find the minimum character in the original string
    int p = 0;
    while (U[p]!= c) {
        p++;
    }
    // Find the index of the minimum character in the concatenated string
    int minindex = p;
    p++;
    while (p <= N) {
        if (U[p] == c) {
            if (check_normal_dict(U, minindex, p)) {
                minindex = p;
            }
        }
        p++;
    }
    return &U[minindex];
    // Transform the string S using the get_last_dict function
}

int check_normal_dict(char* u, int pointer1, int pointer2) {
    for (int i = 0; i < N; i++) {
        if (u[pointer1 + i] > u[pointer2 + i]) {
            return 1;
        } else if (u[pointer1 + i] < u[pointer2 + i]) {
            return 0;
        }
    }
    return 0;
    // Compare two substrings to determine which one is lexicographically smaller
}

// Translate the above C code to Java and end with comment "