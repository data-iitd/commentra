
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize variables
    int n, a[100000], i, l, r, ans;

    // Read the number of elements in the array
    scanf("%d", &n);

    // Read the elements of the array
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize the answer variable
    ans = 0;

    // Iterate through the array
    for (i = 0; i < n; i++) {
        // Initialize left and right indices
        l = i;
        r = i + 1;

        // Use a while loop to find the next index 'r' such that the difference between 'a[r]' and 'a[l]' is negative
        while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
            r++;
        }

        // Increment the answer variable
        ans++;

        // Update the index 'i' to 'r' for the next iteration
        i = r;
    }

    // Print the answer
    printf("%d\n", ans);

    return 0;
}
