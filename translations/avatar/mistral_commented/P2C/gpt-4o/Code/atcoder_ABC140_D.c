#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

// Function to get the next integer from input
int gi() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to get the next string from input
void gw(char *str) {
    scanf("%s", str);
}

int main() {
    // Get the number of segments in the string
    int N = gi();

    // Get the number of queries
    int K = gi();

    // Get the string S
    char S[N + 1]; // +1 for null terminator
    gw(S);

    // Initialize segment count
    int seg_cnt = 0;

    // Iterate through the string and count the number of segments
    for (int i = 0; i < N - 1; i++) {
        // Check if the current character is different from the next character
        if (S[i] != S[i + 1]) {
            seg_cnt++;
        }
    }

    // Calculate the current happiness
    int cur_happy = N - 1 - seg_cnt;

    // Check if the number of queries is greater than or equal to the number of segments
    int ans;
    if (2 * K >= seg_cnt) {
        // If yes, then the answer is the total number of segments
        ans = N - 1;
    } else {
        // Otherwise, the answer is the current happiness plus twice the number of queries
        ans = cur_happy + 2 * K;
    }

    // Print the answer
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
