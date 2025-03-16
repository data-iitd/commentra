#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nextInt() {
    int i;
    scanf("%d", &i);
    return i;
}

int* nextInts(int n) {
    int* slice = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &slice[i]);
    }
    return slice;
}

void puts(int a) {
    printf("%d\n", a);
}

void flush() {
    fflush(stdout);
}

int main() {
    // Read the number of integers
    int n = nextInt();
    // Read the integers into a slice
    int* a = nextInts(n);

    // Initialize the answer counter
    int ans = 0;

    // Iterate through the slice of integers
    for (int i = 0; i < n; i++) {
        // Set the left and right pointers for the current segment
        int l = i, r = i + 1;

        // Expand the right pointer while the conditions are met
        while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
            r++;
        }

        // Increment the answer for each segment found
        ans++;
        // Move the left pointer to the end of the current segment
        i = r;
    }

    // Output the final count of segments
    puts(ans);
    // Flush the output buffer to ensure all output is written
    flush();

    // Free the allocated memory for the slice
    free(a);

    return 0;
}
