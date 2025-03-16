
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Set the scanner to split input by whitespace
    char buf[1000000];
    fgets(buf, sizeof(buf), stdin);
    char *token = strtok(buf, " ");

    // Read the number of integers
    int n = atoi(token);

    // Read the integers into a slice
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        token = strtok(NULL, " ");
        a[i] = atoi(token);
    }

    // Initialize the answer counter
    int ans = 0;

    // Iterate through the slice of integers
    int l = 0, r = 1;
    while (r < n) {
        // Expand the right pointer while the conditions are met
        while (r+1 < n && (a[r]-a[l])*(a[r+1]-a[r]) >= 0) {
            r++;
        }

        // Increment the answer for each segment found
        ans++;
        // Move the left pointer to the end of the current segment
        l = r;
        r++;
    }

    // Output the final count of segments
    printf("%d\n", ans);
    // Flush the buffered writer to ensure all output is written
    fflush(stdout);
}

