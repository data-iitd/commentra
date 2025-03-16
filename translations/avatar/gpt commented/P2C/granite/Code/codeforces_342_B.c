
#include <stdio.h>

int main() {
    // Define a lambda function to read multiple integers from input
    #define R() ({ \
        int x; \
        scanf("%d", &x); \
        x; \
    })

    // Read the values of n (total positions), m (number of obstacles), s (starting position), and f (finishing position)
    int n = R(), m = R(), s = R(), f = R();

    // Determine the direction of movement based on the starting and finishing positions
    char d = s < f? 'R' : 'L';  // Character representing right or left movement
    int c = s < f? 1 : -1;  // Direction of movement (1 for right, -1 for left)

    // Initialize the result string to store the path taken
    char res[n];
    res[n - 1] = '\0';

    // Initialize the step counter and current position
    int i = 1, j = s;

    // Read the first obstacle's position and range
    int t = R(), l = R(), r = R(), k = 1;  // Counter for the number of obstacles processed

    // Loop until the current position reaches the finishing position
    while (j!= f) {
        // Check if we need to read a new obstacle's position and range
        if (i > t && k < m) {
            t = R();  // Read the next obstacle's position
            l = R();  // Read the next obstacle's left range
            r = R();  // Read the next obstacle's right range
            k++;  // Increment the obstacle counter
        }

        // Check if the current position is at an obstacle
        if (i == t && (l <= j || l <= j + c)) {
            res[n - i] = 'X';  // Mark the position with 'X' if it's blocked by an obstacle
        } else {
            res[n - i - 1] = d;  // Append the direction character to the result
            j += c;  // Move to the next position in the determined direction
        }

        i++;  // Increment the step counter
    }

    // Print the resulting path taken
    printf("%s\n", res);

    return 0;
}
