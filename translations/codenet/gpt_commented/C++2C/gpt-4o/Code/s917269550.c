#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare two long long integer variables to store input values
    long long x, y;

    // Read two integer values from standard input
    scanf("%lld %lld", &x, &y);

    // Check if the absolute difference between x and y is less than or equal to 1
    if (abs(x - y) <= 1) {
        // If the condition is true, output "Brown"
        printf("Brown\n");
    } else {
        // If the condition is false, output "Alice"
        printf("Alice\n");
    }

    return 0; // Return 0 to indicate successful execution
<<<<<<< HEAD
} // <END-OF-CODE>
=======
}

// <END-OF-CODE>
>>>>>>> 98c87cb78a (data updated)
