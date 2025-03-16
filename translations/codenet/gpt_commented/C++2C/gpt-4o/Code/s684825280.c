#include <stdio.h>
#include <stdlib.h>

#define SIZE (100000 * 2 + 13)

// Declare a count array initialized to zero with a size of SIZE
int cnt[SIZE];

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Read the number of elements (n) and the number of largest counts to keep (k)
    int n, k;
    scanf("%d %d", &n, &k);

    // Read n integers and count their occurrences
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        // Increment the count for the number x
        cnt[x]++;
    }

    // Create a temporary array to hold the counts of numbers that appeared at least once
    int a[SIZE];
    int a_size = 0;

    // Transfer the counts of numbers that appeared at least once to array a
    for (int i = 0; i < SIZE; ++i) {
        if (cnt[i] > 0) {
            a[a_size++] = cnt[i]; // Add the count to array a
        }
    }

    // Initialize the answer variable to accumulate the result
    int ans = 0;
    // Sort the counts in ascending order
    qsort(a, a_size, sizeof(int), compare);

    // Calculate the number of counts to exclude (m) based on k
    int m = a_size - k;
    // Sum the counts of the smallest m elements
    for (int i = 0; i < m; ++i) {
        ans += a[i]; // Add the count to the answer
    }

    // Output the final answer
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
