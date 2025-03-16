#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to parse input data
void parser(char *data, int *N, int *K, char *S) {
    // Read input and split it into a list of strings
    char *token = strtok(data, " ");
    int i = 0;
    while (token!= NULL) {
        if (i == 0) {
            *N = atoi(token);
        } else if (i == 1) {
            *K = atoi(token);
        } else {
            strcpy(S, token);
        }
        i++;
        token = strtok(NULL, " ");
    }
}

// Function to get the next value from the input parser as a string
char *gw(char *data) {
    // Read input and split it into a list of strings
    char *token = strtok(data, " ");
    return token;
}

// Function to get the next value from the input parser and convert it to an integer
int gi(char *data) {
    // Read input and split it into a list of strings
    char *token = strtok(data, " ");
    return atoi(token);
}

// Define a constant for the modulo operation
#define MOD 1000000007

// Main function
int main() {
    // Read the number of elements N and the integer K from input
    int N, K;
    char S[100000];
    parser(gw(stdin), &N, &K, S);
    // Read the string S from input
    // Initialize a counter for segments
    int seg_cnt = 0;
    // Count the number of segments in the string S
    for (int i = 0; i < N - 1; i++) {
        if (S[i]!= S[i + 1]) {
            seg_cnt++;
        }
    }
    // Calculate the current happiness based on the number of segments
    int cur_happy = N - 1 - seg_cnt;
    // Determine the final answer based on the relationship between K and seg_cnt
    if (2 * K >= seg_cnt) {
        int ans = N - 1; // If K is sufficient to cover all segments
    } else {
        int ans = cur_happy + 2 * K; // Otherwise, calculate based on current happiness and K
    }
    // Print the final answer
    printf("%d\n", ans);
    return 0;
}

