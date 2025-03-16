
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a constant for the modulo operation
#define MOD 100000007

// Function to get the next value from the input parser as a string
char* gw() {
    static char buf[100000];
    scanf("%s", buf);
    return buf;
}

// Function to get the next value from the input parser and convert it to an integer
int gi() {
    int x;
    scanf("%d", &x);
    return x;
}

// Main function to solve the problem
int main() {
    // Read the number of elements N and the integer K from input
    int N = gi();
    int K = gi();
    // Read the string S from input
    char* S = gw();

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
