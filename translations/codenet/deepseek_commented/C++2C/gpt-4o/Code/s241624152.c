#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b); // Read two integers from standard input
    char *ans;

    // Check if either a or b is 1 and determine the winner based on their values
    if (a == 1 || b == 1) {
        if (a == 1 && b == 1) {
            ans = "Draw"; // If both a and b are 1, it's a draw
        } else if (a == 1) {
            ans = "Alice"; // If a is 1, Alice wins
        } else {
            ans = "Bob"; // If b is 1, Bob wins
        }
    } else {
        // If neither a nor b is 1, determine the winner based on their values
        if (a == b) {
            ans = "Draw"; // If a and b are equal, it's a draw
        } else if (a > b) {
            ans = "Alice"; // If a is greater than b, Alice wins
        } else {
            ans = "Bob"; // If b is greater than a, Bob wins
        }
    }

    printf("%s\n", ans); // Output the result to standard output

    return 0;
}

// <END-OF-CODE>
