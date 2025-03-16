#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare variables to hold the number of characters and the answer
    int n, ans = 0;
    char a[100000], b[100000], c[100000];

    // Read the number of characters and the three strings from input
    scanf("%d", &n);
    scanf("%s", a);
    scanf("%s", b);
    scanf("%s", c);

    // Iterate through each character index from 0 to n-1
    for (int i = 0; i < n; i++) {
        // Check if all three characters at index i are the same
        if (a[i] == b[i] && b[i] == c[i]) {
            // Do nothing, as no points are awarded for identical characters
        }
        // Check if any two characters are the same
        else if (a[i] == b[i] || b[i] == c[i] || a[i] == c[i]) {
            // Increment the answer by 1 for matching pairs
            ans++;
        }
        // If all characters are different
        else {
            // Increment the answer by 2 for all different characters
            ans += 2;
        }
    }

    // Output the final answer
    printf("%d\n", ans);
}
