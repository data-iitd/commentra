
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Declare two integer variables to store input values
    int x, y;

    // Read two integer values from standard input
    scanf("%d %d", &x, &y);

    // Check if the absolute difference between x and y is less than or equal to 1
    if (labs(x - y) <= 1) {
        // If the condition is true, output "Brown"
        printf("Brown\n");
    } else {
        // If the condition is false, output "Alice"
        printf("Alice\n");
    }

    return 0; // Return 0 to indicate successful execution
}
