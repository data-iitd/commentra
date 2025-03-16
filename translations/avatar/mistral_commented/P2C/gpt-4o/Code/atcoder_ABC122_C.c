#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of 'AC' substrings in the given string 's'
int count_ac_substrings(const char *s, int n) {
    int total = 0;
    for (int i = 1; i < n; i++) {
        if (s[i-1] == 'A' && s[i] == 'C') {
            total++;
        }
    }
    return total;
}

int main() {
    // Taking input for number of strings 'n' and number of problems 'q'
    int n, q;
    scanf("%d %d", &n, &q);

    // Taking input for the string 's'
    char *s = (char *)malloc((n + 1) * sizeof(char));
    scanf("%s", s);

    // Array to store cumulative sums of 'AC' substrings
    int *cumsum = (int *)malloc((n + 1) * sizeof(int));
    cumsum[0] = 0;

    // Calculate cumulative sums of 'AC' substrings
    for (int i = 1; i < n; i++) {
        cumsum[i] = cumsum[i - 1] + (s[i - 1] == 'A' && s[i] == 'C' ? 1 : 0);
    }

    // Iterating through each problem and printing the difference between the cumulative sums
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        // Print the difference between the cumulative sum at the end and start of the problem
        printf("%d\n", cumsum[r - 1] - cumsum[l - 1]);
    }

    // Free allocated memory
    free(s);
    free(cumsum);

    return 0;
}

// <END-OF-CODE>
