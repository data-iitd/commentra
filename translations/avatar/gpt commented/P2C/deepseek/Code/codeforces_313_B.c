#include <stdio.h>
#include <string.h>

#define MAX_LEN 100000

int main() {
    char soz[MAX_LEN + 1];
    int a[MAX_LEN + 1];
    int n, m, l;

    // Read the input string from the user
    scanf("%s", soz);

    // Initialize the cumulative count array 'a'
    a[0] = 0;

    // Iterate through the string to fill the cumulative count array 'a'
    for (int i = 1; i < strlen(soz); i++) {
        // Carry forward the previous count
        a[i] = a[i - 1];

        // If the current character is the same as the previous one, increment the count
        if (soz[i - 1] == soz[i]) {
            a[i]++;
        }
    }

    // Read the number of queries from the user
    scanf("%d", &n);

    // Process each query
    for (int i = 0; i < n; i++) {
        // Read the start and end indices for the query
        scanf("%d %d", &m, &l);

        // Calculate the number of consecutive characters between indices m and l
        // and print the result
        printf("%d\n", a[l - 1] - a[m - 1]);
    }

    return 0;
}
