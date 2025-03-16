#include <stdio.h>

int main() {
    // Declare variables
    int n, k, z;
    
    // Read input from the user
    scanf("%d %d", &n, &k);
    
    // Increment n by 1
    n++;
    
    // Initialize z to store the adjustment needed to make n divisible by k
    z = 0;
    
    // Check if n is not divisible by k
    if (n % k != 0) {
        // Calculate the adjustment needed to make n divisible by k
        z = k - n % k;
    }
    
    // Output the final result, which is n plus the adjustment z
    printf("%d\n", n + z);
    
    // End of code
    return 0;
}
