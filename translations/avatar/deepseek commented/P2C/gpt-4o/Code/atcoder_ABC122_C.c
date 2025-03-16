#include <stdio.h>
#include <string.h>

int main() {
    int n, q;
    
    // Read the length of the string and the number of queries
    scanf("%d %d", &n, &q);
    
    // Read the string
    char s[n + 1];
    scanf("%s", s);
    
    // Prepare an array to store cumulative counts of 'AC'
    int cumsum[n];
    cumsum[0] = 0; // Initial count is 0
    
    // Compute the cumulative sum of occurrences of 'AC'
    for (int i = 1; i < n; i++) {
        cumsum[i] = cumsum[i - 1];
        if (s[i - 1] == 'A' && s[i] == 'C') {
            cumsum[i]++;
        }
    }
    
    // Iterate over the queries and print the difference in cumulative sums
    for (int j = 0; j < q; j++) {
        int l, r;
        scanf("%d %d", &l, &r);
        // Output the result for the current query
        printf("%d\n", cumsum[r - 1] - cumsum[l - 1]);
    }
    
    return 0;
}

// <END-OF-CODE>
