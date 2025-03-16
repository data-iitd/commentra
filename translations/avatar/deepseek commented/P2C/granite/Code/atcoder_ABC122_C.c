

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the length of the string and the number of queries
    int n, q;
    scanf("%d %d", &n, &q);

    // Read the string
    char s[n];
    scanf("%s", s);

    // Define a function to count occurrences of 'AC' in the string
    int count(int total, int i) {
        // Check if the current substring is 'AC'
        if (s[i-1] == 'A' && s[i] == 'C') {
            // Increment the count if 'AC' is found
            return total + 1;
        } else {
            // Return the total count if 'AC' is not found
            return total;
        }
    }

    // Compute the cumulative sum of the list [0] + list(range(1, n)) using the count function
    int cumsum[n];
    cumsum[0] = 0;
    for (int i = 1; i < n; i++) {
        cumsum[i] = cumsum[i-1] + count(0, i);
    }

    // Iterate over the queries and print the difference in cumulative sums
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", cumsum[r-1] - cumsum[l-1]);
    }

    return 0;
}
