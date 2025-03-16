
#include <stdio.h> // Include the standard input/output library

int main() {
    // Declare and initialize variables n and k
    int n, k;
    scanf("%d %d", &n, &k);
    
    // Increment n by 1
    n++;
    
    // Initialize a variable z to store the adjustment needed to make n divisible by k
    int z = 0;
    
    // Check if n is not divisible by k
    if (n % k!= 0) {
        // Calculate the adjustment needed to make n divisible by k
        z = k - n % k;
    }
    
    // Output the final result, which is n plus the adjustment z
    printf("%d\n", n + z);
    
    // End the program
    return 0;
}

