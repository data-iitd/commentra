#include <stdio.h>

int main() {
    // Declare variables to hold the number of operations (n) and the sequence of operations (s)
    int n;
    char s[100001]; // Assuming the maximum length of s is 100000

    // Read input values for n and s from the standard input
    scanf("%d %s", &n, s);

    // Initialize variables to track the maximum count and the current count
    int max = 0;
    int cnt = 0;

    // Iterate over each character in the string s
    for (int i = 0; i < n; i++) {
        // Increment count for 'I' and decrement for any other character
        if (s[i] == 'I') {
            cnt++;
        } else {
            cnt--;
        }

        // Update max if the current count exceeds the previously recorded maximum
        if (cnt > max) {
            max = cnt;
        }
    }

    // Print the maximum count achieved during the iterations
    printf("%d\n", max);

    return 0;
}

// <END-OF-CODE>
