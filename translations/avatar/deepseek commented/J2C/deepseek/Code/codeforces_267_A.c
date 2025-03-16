#include <stdio.h>
#include <stdlib.h>

// Function to calculate the greatest common divisor using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    // Create a new Scanner object to read input from the user
    int n;
    scanf("%d", &n);
    
    // Loop n times to read pairs of integers and print their greatest common divisor
    for (int i = 0; i < n; i++) {
        // Read two integers a and b from the user and store them in the variables a and b
        int a, b;
        scanf("%d %d", &a, &b);
        
        // Call the gcd function with the values of a and b as arguments and print the result
        printf("%d\n", gcd(a, b));
    }
    
    return 0;
}
