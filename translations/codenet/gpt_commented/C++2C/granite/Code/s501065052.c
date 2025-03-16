
#include <stdio.h>

int main(void) {
    // Read the number of elements
    int N;
    scanf("%d", &N);

    // Create an array to store the positions of elements
    int mem[N + 1];

    // Populate the'mem' array with the positions of each element
    for (int i = 1; i <= N; ++i) {
        int P;
        scanf("%d", &P); // Read the element
        mem[P] = i; // Store the position of the element in'mem'
    }

    // Initialize counters for the longest increasing subsequence
    int maxcnt = 1; // Maximum count of increasing sequence found
    int cnt = 1; // Current count of increasing sequence

    // Iterate through the'mem' array to find the longest increasing subsequence
    for (int i = 1; i < N; ++i) {
        // Check if the current position is less than the next position
        if (mem[i] < mem[i + 1]) {
            cnt++; // Increment the current count if increasing
        } else {
            // Update the maximum count if the current count is greater
            maxcnt = (maxcnt > cnt)? maxcnt : cnt;
            cnt = 1; // Reset current count
        }
        // Check at the last element to update max count
        if (i == N - 1) {
            maxcnt = (maxcnt > cnt)? maxcnt : cnt;
        }
    }

    // Output the minimum number of elements to remove to get the longest increasing subsequence
    printf("%d\n", N - maxcnt);

    return 0; // End of the program
}
