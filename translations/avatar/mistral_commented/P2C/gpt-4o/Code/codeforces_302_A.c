#include <stdio.h>

int main() {
    // Define the number of strings n and the number of operations m
    int n, m;
    scanf("%d %d", &n, &m);

    // Calculate the number of '-' symbols in the input string
    char input[100000]; // Assuming the input string can be up to 100000 characters
    scanf("%s", input);
    
    int sa = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '-') {
            sa++;
        }
    }

    // Ensure the number of '-' symbols is valid
    sa = (n - sa < sa) ? n - sa : sa;

    // Initialize an empty result array
    char ss[1000000]; // Assuming the result can be up to 1000000 characters
    int index = 0;

    // Perform each operation as described in the problem statement
    for (int i = 0; i < m; i++) {
        // Read two integers a and b from the input
        int a, b;
        scanf("%d %d", &a, &b);

        // Calculate the difference between b and a
        b -= a;

        // Check if the difference is valid based on the number of '-' symbols
        if (b % 2 == 0 || b > (sa << 1)) {
            // If the difference is valid, add '1' to the result array
            index += sprintf(ss + index, "1\n");
        } else {
            // If the difference is not valid, add '0' to the result array
            index += sprintf(ss + index, "0\n");
        }
    }

    // Print the final result
    printf("%s", ss);

    return 0;
}

// <END-OF-CODE>
