#include <stdio.h>
#include <stdlib.h>

void out(int x) {
    printf("%d\n", x);
}

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to read an integer from standard input
int getInt() {
    int i;
    scanf("%d", &i);
    return i;
}

// Main function
int main() {
    // Read input: N, C, K
    int N = getInt();
    int C = getInt();
    int K = getInt();

    // Initialize array t of size N
    int *t = (int *)malloc(N * sizeof(int));

    // Read input: t[i] for i from 0 to N-1
    for (int i = 0; i < N; i++) {
        t[i] = getInt();
    }

    // Sort array t in ascending order
    qsort(t, N, sizeof(int), compare);

    // Initialize variables: answer counter ans, counter cnt, and end index end
    int ans = 1;
    int cnt = 1;
    int end = t[0] + K;

    // Iterate through array t from index 1 to N-1
    for (int i = 1; i < N; i++) {
        // If counter cnt is less than C and current element t[i] is within the range [end, end+K], increment counter cnt
        if (cnt < C && t[i] <= end) {
            cnt++;
        } else {
            // Reset counter cnt and update end index end to the current element t[i] plus K
            cnt = 1;
            end = t[i] + K;
            // Increment answer counter ans
            ans++;
        }
    }

    // Print the final answer
    out(ans);

    // Free allocated memory
    free(t);

    return 0;
}

// <END-OF-CODE>
