
#include <stdio.h>

int main() {
    // Define the number of strings n and the number of operations m
    int n, m;
    scanf("%d %d", &n, &m);

    // Calculate the number of '-' symbols in the input string
    int sa = 0;
    char s[100001];
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] == '-') {
            sa++;
        }
    }

    // Ensure the number of '-' symbols is valid
    sa = sa < n - sa? sa : n - sa;

    // Initialize an empty list'ss' to store the results of each operation
    char ss[m][2];

    // Perform each operation as described in the problem statement
    for (int i = 0; i < m; i++) {
        // Read two integers a and b from the input
        int a, b;
        scanf("%d %d", &a, &b);

        // Calculate the difference between b and a
        b -= a;

        // Check if the difference is valid based on the number of '-' symbols
        if (b % 2 == 0 || b > sa * 2) {
            // If the difference is valid, add '1' to the result list'ss'
            ss[i][0] = '1';
            ss[i][1] = '\n';
        } else {
            // If the difference is not valid, add '0' to the result list'ss'
            ss[i][0] = '0';
            ss[i][1] = '\n';
        }
    }

    // Print the final result by joining all the strings in the'ss' list with an empty string as separator
    for (int i = 0; i < m; i++) {
        printf("%s", ss[i]);
    }

    return 0;
}
