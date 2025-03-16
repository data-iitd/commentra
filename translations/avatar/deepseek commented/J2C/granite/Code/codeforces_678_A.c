
#include <stdio.h> // Step 1: Include the necessary header file for input/output operations.

int main() { // Step 2: Define the main function.
    int n, k, z; // Step 3: Declare the variables n, k, and z.
    
    scanf("%d %d", &n, &k); // Step 4: Read two integer values from the user and store them in n and k respectively.
    
    n++; // Step 5: Increment the value of n by 1.
    
    z = 0; // Step 6: Initialize z to 0.
    
    if (n % k!= 0) { // Step 7: Check if n is not divisible by k.
        z = k - n % k; // If true, calculate the difference between k and the remainder of n divided by k, and store it in z.
    }
    
    printf("%d\n", n + z); // Step 8: Print the new value of n plus the value of z.
    
    return 0; // Step 9: Return 0 to indicate successful execution of the program.
}
