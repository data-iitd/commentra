#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(long long*)a - *(long long*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    long long ans[n];
    
    // Populate the array with input values
    for (int i = 0; i < n; i++) {
        scanf("%lld", &ans[i]);
    }
    
    // Sort the array in ascending order
    qsort(ans, n, sizeof(long long), compare);
    
    // Initialize count with the largest element in the array
    long long count = ans[n - 1];
    
    // Iterate through the array from the second-to-last element to the first
    for (int i = n - 2; i >= 0; i--) {
        if (ans[i] < ans[i + 1]) {
            count += ans[i]; // Add the current element to count if it's less than the next element
        } else {
            while (ans[i] >= ans[i + 1]) {
                ans[i]--; // Decrease the current element until it's less than the next element
            }
            if (ans[i] > 0) {
                count += ans[i]; // Add the adjusted current element to count
            }
        }
    }
    
    // Print the final count
    printf("%lld\n", count);
    
    return 0;
}
