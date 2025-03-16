#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Allocate memory for t and a, and prepend a 0 for 1-based indexing
    int *t = (int *)malloc((n + 1) * sizeof(int));
    int *a = (int *)malloc((n + 1) * sizeof(int));
    t[0] = 0; // 1-based indexing
    a[0] = 0; // 1-based indexing

    // Read the list 't'
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }

    // Read the list 'a'
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize the answer list and a count array to track occurrences
    int *ans = (int *)malloc((n + 1) * sizeof(int));
    int *cnt = (int *)calloc(n + 1, sizeof(int));
    int ans_length = 0;

    // Count the occurrences of each element in list 'a'
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
    }

    // Iterate through each index from 1 to n
    for (int i = 1; i <= n; i++) {
        // Check if the current element in 't' is 1
        if (t[i] == 1) {
            // Initialize a current path array starting with the current index
            int crt[1000]; // Assuming the maximum length of the path won't exceed 1000
            int crt_length = 0;
            crt[crt_length++] = i; // Add current index to path
            int x = a[i];

            // Continue to follow the chain while the count of x is 1
            while (cnt[x] == 1) {
                crt[crt_length++] = x; // Add x to the current path
                x = a[x]; // Move to the next index in the chain
            }

            // Update the answer if the current path is longer than the previous answer
            if (crt_length > ans_length) {
                ans_length = crt_length;
                for (int j = 0; j < crt_length; j++) {
                    ans[j] = crt[j]; // Store a copy of the current path
                }
            }
        }
    }

    // Print the length of the longest path found
    printf("%d\n", ans_length);

    // Print the elements of the longest path as a space-separated string
    for (int i = 0; i < ans_length; i++) {
        printf("%d", ans[i]);
        if (i < ans_length - 1) {
            printf(" ");
        }
    }
    printf("\n");

    // Free allocated memory
    free(t);
    free(a);
    free(ans);
    free(cnt);

    return 0;
}

// <END-OF-CODE>
