#include <stdio.h>
#include <stdlib.h>

// Function to count occurrences of 'AC' in the string
int count(int total, int i, char *s) {
    // Check if the current substring is 'AC'
    if (s[i-1] == 'A' && s[i] == 'C') {
        // Increment the count if 'AC' is found
        return total + 1;
    } else {
        // Return the total count if 'AC' is not found
        return total;
    }
}

int main() {
    int n, q;
    // Read the length of the string and the number of queries
    scanf("%d %d", &n, &q);

    // Read the string
    char *s = (char *)malloc(n + 1);
    scanf("%s", s);

    // Allocate memory for the cumulative sum array
    int *cumsum = (int *)malloc((n + 1) * sizeof(int));
    cumsum[0] = 0;

    // Compute the cumulative sum of the list [0] + list(range(1, n)) using the count function
    for (int i = 1; i <= n; i++) {
        cumsum[i] = count(cumsum[i-1], i, s);
    }

    // Iterate over the queries and print the difference in cumulative sums
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", cumsum[r-1] - cumsum[l-1]);
    }

    // Free allocated memory
    free(s);
    free(cumsum);

    return 0;
}
