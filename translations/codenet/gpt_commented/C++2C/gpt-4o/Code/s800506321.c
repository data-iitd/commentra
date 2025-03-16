#include <stdio.h>

int main(void)
{
    // Declare variables to hold input values and intermediate results
    int n, k, x, y, z;

    // Read the total number of items (n) from user input
    scanf("%d", &n);
    
    // Read the number of groups (k) from user input
    scanf("%d", &k);
    
    // Calculate the number of items in each group (integer division)
    x = n / k;
    
    // Calculate the remainder to check if there are leftover items
    y = n % k;

    // Check if there are leftover items after dividing into groups
    if (y != 0) {
        // If there are leftovers, set z to 1 (indicating at least one group has one extra item)
<<<<<<< HEAD
        z = 1; // This indicates there is at least one leftover
    } else {
        // If there are no leftovers, set z to 0 (indicating all groups are even)
        z = 0; // This indicates there are no leftovers
=======
        z = 1;
    } else {
        // If there are no leftovers, set z to 0 (indicating all groups are even)
        z = 0;
>>>>>>> 98c87cb78a (data updated)
    }

    // Output the result (0 or 1) indicating if there are leftover items
    printf("%d\n", z);
    
    return 0; // End of the program
}

// <END-OF-CODE>
