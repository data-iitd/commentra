#include <stdio.h> // Step 1: Include the standard input-output library.

int main() { // Step 2: Define the main function.
    int n, k; // Step 3: Declare integer variables n and k.
    
    scanf("%d", &n); // Step 4: Read an integer value from the user and store it in n.
    scanf("%d", &k); // Step 5: Read another integer value from the user and store it in k.
    
    n++; // Step 6: Increment the value of n by 1.
    
    int z = 0; // Step 7: Initialize a variable z to 0.
    
    if (n % k != 0) { // Step 8: Check if n is not divisible by k.
        z = k - n % k; // If true, calculate the difference between k and the remainder of n divided by k, and store it in z.
    }
    
    printf("%d\n", n + z); // Step 9: Print the new value of n plus the value of z.
    
    return 0; // Step 10: Return 0 to indicate successful completion of the program.
}

// <END-OF-CODE>
