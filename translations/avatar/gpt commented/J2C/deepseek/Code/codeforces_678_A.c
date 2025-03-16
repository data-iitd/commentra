#include <stdio.h>

int main() {
    int n, k, z = 0;
    
    // Read two integers from the user: n and k
    scanf("%d %d", &n, &k);
    
    // Increment n by 1
    n++;
    
    // Check if n is not divisible by k
    if (n % k != 0) {
        // Calculate the adjustment needed to make n divisible by k
        z = k - n % k;
    }
    
    // Output the final result, which is n plus the adjustment z
    printf("%d\n", n + z);
    
    return 0;
}
