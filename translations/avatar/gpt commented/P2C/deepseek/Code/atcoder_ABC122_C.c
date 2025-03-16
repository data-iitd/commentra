#include <stdio.h>
#include <stdlib.h>

// Function to count occurrences of 'AC' in the string
int count(int total, int i, char *s) {
    // Increment total if the substring from index i-1 to i is 'AC'
    return total + 1;
}

int main() {
    int n, q;
    // Read the number of characters in the string and the number of queries
    scanf("%d %d", &n, &q);

    // Read the input string
    char *s = (char *)malloc(n + 1);
    scanf("%s", s);

    // Read the queries, each containing two integers l and r
    int **problems = (int **)malloc(q * sizeof(int *));
    for (int i = 0; i < q; i++) {
        problems[i] = (int *)malloc(2 * sizeof(int));
        scanf("%d %d", &problems[i][0], &problems[i][1]);
    }

    // Create a cumulative sum array to keep track of 'AC' occurrences
    int *cumsum = (int *)malloc((n + 1) * sizeof(int));
    cumsum[0] = 0;
    for (int i = 1; i < n; i++) {
        cumsum[i] = cumsum[i - 1];
        if (s[i - 1] == 'A' && s[i] == 'C') {
            cumsum[i]++;
        }
    }

    // Process each query to find the number of 'AC' occurrences in the specified range
    for (int i = 0; i < q; i++) {
        int l = problems[i][0];
        int r = problems[i][1];
        // Output the difference in cumulative sums to get the count in the range [l, r]
        printf("%d\n", cumsum[r - 1] - cumsum[l - 1]);
    }

    // Free allocated memory
    free(s);
    for (int i = 0; i < q; i++) {
        free(problems[i]);
    }
    free(problems);
    free(cumsum);

    return 0;
}
