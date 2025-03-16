#include <stdio.h>

int main() {
    int n, k, i = 1, req;
    
    // Reading two integer inputs: n and k
    scanf("%d %d", &n, &k);
    
    req = 1; // Initializing req to 1, which represents the current decrement value
    
    // Loop to decrement k until it is no longer possible
    while (k - req >= 0) {
        // Check if k can be decremented by req
        if (k - req >= 0) {
            k = k - req; // Decrement k by req
        } else {
            break; // Exit the loop if k cannot be decremented by req
        }
        
        i++; // Increment i to determine the next req value
        
        // Determine the next req value based on the current value of i
        if (i % n != 0) {
            req = i % n; // If i is not a multiple of n, set req to i % n
        } else {
            req = n; // If i is a multiple of n, set req to n
        }
    }
    
    // Output the final value of k after all possible decrements
    printf("%d\n", k);
    
    return 0;
}
