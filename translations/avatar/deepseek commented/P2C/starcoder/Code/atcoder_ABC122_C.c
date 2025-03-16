
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read the length of the string and the number of queries
    int n, q;
    scanf("%d %d", &n, &q);

    // Read the string
    char s[n+1];
    scanf("%s", s);

    // Read the queries
    int problems[q][2];
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &problems[i][0], &problems[i][1]);
    }

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
        cumsum[i] = count(cumsum[i-1], i);
    }

    // Iterate over the queries and print the difference in cumulative sums
    for (int i = 0; i < q; i++) {
        printf("%d\n", cumsum[problems[i][1]-1] - cumsum[problems[i][0]-1]);
    }

    return 0;
}

