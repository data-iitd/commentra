#include <stdio.h>
#include <string.h>

int main() {
    int n, q;
    
    // Read the number of characters in the string and the number of queries
    scanf("%d %d", &n, &q);
    
    // Read the input string
    char s[n + 1];
    scanf("%s", s);
    
    // Create an array to store cumulative sums of 'AC' occurrences
    int cumsum[n];
    cumsum[0] = 0; // Initialize the first element
    
    // Count occurrences of 'AC' and fill the cumulative sum array
    for (int i = 1; i < n; i++) {
        cumsum[i] = cumsum[i - 1];
        if (s[i - 1] == 'A' && s[i] == 'C') {
            cumsum[i]++;
        }
    }
    
    // Process each query to find the number of 'AC' occurrences in the specified range
    for (int j = 0; j < q; j++) {
        int l, r;
        scanf("%d %d", &l, &r);
        // Output the difference in cumulative sums to get the count in the range [l, r]
        printf("%d\n", cumsum[r - 1] - cumsum[l - 1]);
    }
    
    return 0;
}

// <END-OF-CODE>
