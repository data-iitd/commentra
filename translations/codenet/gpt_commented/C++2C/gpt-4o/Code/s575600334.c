#include <stdio.h>

// Function to print the binary representation of an integer
void binPrint(unsigned int x, int bits) {
    // Loop through each bit from the most significant to the least significant
    for (int i = bits - 1; i >= 0; i--) {
        // Print 1 if the ith bit is set, otherwise print 0
<<<<<<< HEAD
        printf("%d", (x & (1 << i)) ? 1 : 0);
=======
        printf("%d", (x & (1U << i)) ? 1 : 0);
>>>>>>> 98c87cb78a (data updated)
    }
    // Print a newline after the binary representation
    printf("\n");
}

int main(void) {
    // Declare two unsigned integers to hold user input
    unsigned int a, b;
    
    // Read two unsigned integers from standard input
    scanf("%u %u", &a, &b);

    // Print the binary representation of the bitwise AND of a and b
    binPrint(a & b, 32);
    
    // Print the binary representation of the bitwise OR of a and b
    binPrint(a | b, 32);
    
    // Print the binary representation of the bitwise XOR of a and b
    binPrint(a ^ b, 32);
    
    // Return 0 to indicate successful execution
    return 0;
}

// <END-OF-CODE>
