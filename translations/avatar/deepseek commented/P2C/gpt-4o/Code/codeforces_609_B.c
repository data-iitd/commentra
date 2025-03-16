#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int *lst = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &lst[i]);
    }

    // Initialize a frequency array (assuming elements are non-negative and within a reasonable range)
    int *freq = (int *)calloc(100001, sizeof(int)); // Adjust size as needed based on input constraints

    // Populate the frequency array
    for (int i = 0; i < n; i++) {
        freq[lst[i]]++;
    }

    long long res = 0; // Use long long to avoid overflow

    // Iterate over the list to calculate the result
    for (int i = 0; i < n; i++) {
        if (freq[lst[i]] > 1) {
            // Calculate the number of pairs that can be formed with the current element
            res += n - i - freq[lst[i]];
            // Decrement the frequency of the current element in the array
            freq[lst[i]]--;
        } else {
            // If the frequency is not greater than 1, calculate the number of pairs
            res += n - i - 1;
        }
    }

    // Print the final result
    printf("%lld\n", res);

    // Free allocated memory
    free(lst);
    free(freq);

    return 0;
}

// <END-OF-CODE>
