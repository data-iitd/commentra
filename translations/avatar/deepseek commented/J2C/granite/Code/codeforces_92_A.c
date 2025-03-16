
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, i, req;
    scanf("%d %d", &n, &k); // Read the number of elements in the sequence and the initial value of k
    i = 1;
    req = 1;
    
    // Loop continues as long as k - req is non-negative
    while (k - req >= 0) {
        if (k - req >= 0) {
            k = k - req; // Subtract req from k if k - req is non-negative
        } else {
            break; // Exit the loop if k - req is negative
        }
        i++; // Increment i
        if (i % n!= 0) {
            req = i % n; // Update req to i % n if i % n is not zero
        } else {
            req = n; // Update req to n if i % n is zero
        }
    }
    
    printf("%d", k); // Print the final value of k
    
    return 0;
}
