#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;  // Number of elements in the list
    scanf("%d", &n);  // Read the number of elements
    int *l = (int *)malloc(n * sizeof(int));  // Dynamically allocate memory for the list

    // Read n elements and store them in the list l
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    long long ans = n - 1;  // Initialize ans to n - 1
    int last = 0;  // Initialize last to 0

    // Iterate over each element in the list l
    for (int i = 0; i < n; i++) {
        ans += abs(last - l[i]) + 1;  // Update ans based on the current element and last element
        last = l[i];  // Update last to the current element
    }

    printf("%lld\n", ans);  // Print the final answer

    free(l);  // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
