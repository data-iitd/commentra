#include <stdio.h>
#include <string.h>

int main() {
    // Read the input string from the user
    char soz[100001]; // Assuming the maximum length of the input string is 100000
    scanf("%s", soz);

    // Initialize an array 'a' to store the cumulative count of consecutive characters
    int len = strlen(soz);
    int a[len + 1]; // Length of 'a' is one more than the length of 'soz'
    a[0] = 0; // Base case

    // Iterate through the string to fill the cumulative count array 'a'
    for (int i = 1; i < len; i++) {
        // Carry forward the previous count
        a[i] = a[i - 1];

        // If the current character is the same as the previous one, increment the count
        if (soz[i - 1] == soz[i]) {
            a[i]++;
        }
    }

    // Read the number of queries from the user
    int n;
    scanf("%d", &n);

    // Process each query
    for (int i = 0; i < n; i++) {
        int m, l;
        scanf("%d %d", &m, &l);

        // Calculate the number of consecutive characters between indices m and l
        // and print the result
        printf("%d\n", a[l - 1] - a[m - 1]);
    }

    return 0;
}

// <END-OF-CODE>
