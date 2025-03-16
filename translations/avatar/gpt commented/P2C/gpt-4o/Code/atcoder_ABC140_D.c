#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

// Function to read the next integer from input
int gi() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read the next string from input
void gw(char *str, int size) {
    scanf("%s", str);
}

int main() {
    // Read the number of elements N and the integer K from input
    int N = gi();
    int K = gi();
    
    // Read the string S from input
    char S[N + 1]; // +1 for null terminator
    gw(S, sizeof(S));

    // Initialize a counter for segments
    int seg_cnt = 0;

    // Count the number of segments in the string S
    for (int i = 0; i < N - 1; i++) {
        if (S[i] != S[i + 1]) {
            seg_cnt++;
        }
    }

    // Calculate the current happiness based on the number of segments
    int cur_happy = N - 1 - seg_cnt;

    // Determine the final answer based on the relationship between K and seg_cnt
    int ans;
    if (2 * K >= seg_cnt) {
        ans = N - 1;  // If K is sufficient to cover all segments
    } else {
        ans = cur_happy + 2 * K;  // Otherwise, calculate based on current happiness and K
    }

    // Print the final answer
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
