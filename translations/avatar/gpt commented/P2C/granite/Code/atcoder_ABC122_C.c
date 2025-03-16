
#include <stdio.h>

int main() {
    // Read the number of characters in the string and the number of queries
    int n, q;
    scanf("%d %d", &n, &q);

    // Read the input string
    char s[n];
    scanf("%s", s);

    // Read the queries, each containing two integers l and r
    int problems[q][2];
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &problems[i][0], &problems[i][1]);
    }

    // Define a function to count occurrences of 'AC' in the string
    int count(int total, int i) {
        // Increment total if the substring from index i-1 to i is 'AC'
        return total + (s[i - 1] == 'A' && s[i] == 'C');
    }

    // Create a cumulative sum array to keep track of 'AC' occurrences
    int cumsum[n];
    cumsum[0] = count(0, 1);
    for (int i = 1; i < n; i++) {
        cumsum[i] = cumsum[i - 1] + count(cumsum[i - 1], i + 1);
    }

    // Process each query to find the number of 'AC' occurrences in the specified range
    for (int i = 0; i < q; i++) {
        int l = problems[i][0], r = problems[i][1];
        // Output the difference in cumulative sums to get the count in the range [l, r]
        printf("%d\n", cumsum[r - 1] - cumsum[l - 1]);
    }

    return 0;
}
