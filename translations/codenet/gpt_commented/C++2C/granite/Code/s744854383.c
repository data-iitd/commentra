
#include <stdio.h>

int main() {
    // Read the number of elements
    int N;
    scanf("%d", &N);

    // Initialize an array to store the elements
    int a[N];
    // Read the elements into the array
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize index and answer counter
    int idx = 1;
    int ans = 0;

    // Iterate through the array to count mismatches
    for (int i = 0; i < N; i++) {
        // If the current element matches the expected index
        if (a[i] == idx) {
            // Move to the next expected index
            idx++;
        } else {
            // Count the mismatch
            ans++;
        }
    }

    // If no elements matched the expected index
    if (idx == 1) {
        printf("-1\n"); // Output -1 to indicate no matches
    } else {
        // Output the count of mismatches
        printf("%d\n", ans);
    }

    return 0; // End of the program
}
