
#include <stdio.h>

int main() {
    // Read the values of n and m from input
    int n, m;
    scanf("%d %d", &n, &m);

    // Read a list of integers from input
    int lst[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &lst[i]);
    }

    // Initialize a dictionary to count occurrences of each integer in the list
    int l[m + 1] = {0};
    for (int i = 0; i < n; i++) {
        l[lst[i]]++;
    }

    // Initialize the result variable to store the final count
    int res = 0;

    // Calculate the result based on the occurrences of integers
    for (int i = 0; i < n; i++) {
        if (l[lst[i]] > 1) {
            // If the current integer appears more than once
            res += n - i - l[lst[i]];  // Add the number of valid pairs
            l[lst[i]]--;  // Decrease the count of this integer
        } else {
            // If the current integer appears only once
            res += n - i - 1;  // Add the number of valid pairs for unique integers
        }
    }

    // Print the final result
    printf("%d\n", res);

    return 0;
}
