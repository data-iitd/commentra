#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007

// Generator function to parse input data
void parser(char *data, int *data_len) {
    char *p = data;
    char *q = data;
    while (1) {
        // Read input and split it into a list of strings
        scanf("%s", p);
        // Yield each non-empty string as a separate value
        if (strlen(p) > 0) {
            *data_len += 1;
            p += strlen(p) + 1;
        }
    }
}

// Function to get the next value from the input parser as a string
char *gw(char *data, int *data_len) {
    static int i = 0;
    if (i < *data_len) {
        char *p = data;
        for (int j = 0; j < i; j++) {
            p += strlen(p) + 1;
        }
        char *q = p;
        p += strlen(p) + 1;
        i++;
        return q;
    } else {
        return NULL;
    }
}

// Function to get the next value from the input parser and convert it to an integer
int gi(char *data, int *data_len) {
    char *p = gw(data, data_len);
    return atoi(p);
}

// Define a constant for the modulo operation
#define MOD 1000000007

// Import necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Read the number of elements N and the integer K from input
int N = gi(data, &data_len);
int K = gi(data, &data_len);
// Read the string S from input
char *S = gw(data, &data_len);

// Initialize a counter for segments
int seg_cnt = 0;

// Count the number of segments in the string S
for (int i = 0; i < N - 1; i++) {
    if (S[i] != S[i + 1]) {
        seg_cnt += 1;
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

