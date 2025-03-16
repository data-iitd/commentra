#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    // Read two integers n and m from input

    char input[100]; // Assuming the input string will not exceed 100 characters
    scanf("%s", input);
    // Read the input string

    int sa = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '-') {
            sa++;
        }
    }
    // Count the number of '-' characters in the input

    sa = (n - sa < sa) ? (n - sa) : sa;
    // Set sa to the minimum of n - sa and sa, possibly normalizing sa

    char ss[1000] = ""; // Initialize an empty string to store results
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        // Read two integers a and b in each iteration of the loop

        b -= a;
        // Subtract a from b

        if (b % 2 && b <= sa * 2) {
            // Check if b is odd and within certain bounds
            strcat(ss, "1\n");
            // Append "1\n" to ss if condition is met
        } else {
            strcat(ss, "0\n");
            // Append "0\n" to ss otherwise
        }
    }

    printf("%s", ss);
    // Print the contents of ss

    return 0;
}
// <END-OF-CODE>
