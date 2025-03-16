#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int t[n + 1], a[n + 1];
    t[0] = 0;
    a[0] = 0;

    // Read the list 't' and prepend a 0 for 1-based indexing
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }

    // Read the list 'a' and prepend a 0 for 1-based indexing
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize the answer list and a count list to track occurrences
    int cnt[n + 1];
    for (int i = 0; i <= n; i++) {
        cnt[i] = 0;
    }

    // Count the occurrences of each element in list 'a'
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
    }

    int ans[n + 1], ans_size = 0;

    // Iterate through each index from 1 to n
    for (int i = 1; i <= n; i++) {
        // Check if the current element in 't' is 1
        if (t[i] == 1) {
            // Initialize a current path list starting with the current index
            int crt[n + 1], crt_size = 0;
            crt[crt_size++] = i;
            // Set x to the corresponding value in 'a'
            int x = a[i];

            // Continue to follow the chain while the count of x is 1
            while (cnt[x] == 1) {
                crt[crt_size++] = x;  // Add x to the current path
                x = a[x];  // Move to the next index in the chain
            }

            // Update the answer if the current path is longer than the previous answer
            if (crt_size > ans_size) {
                ans_size = crt_size;
                for (int j = 0; j < crt_size; j++) {
                    ans[j] = crt[crt_size - j - 1];
                }
            }
        }
    }

    // Print the length of the longest path found
    printf("%d\n", ans_size);

    // Print the elements of the longest path as a space-separated string
    for (int i = 0; i < ans_size; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", ans[i]);
    }
    printf("\n");

    return 0;
}
