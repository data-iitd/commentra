

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a variable x and initialize it to 0
    int x = 0;
    // Create a variable count and initialize it to 0
    int count = 0;
    // Create a variable tmp and initialize it to the value of x
    int tmp = x;
    
    // Loop until x becomes 360
    while (x!= 360) {
        // Increment x by tmp
        x = x + tmp;
        // If x exceeds 360, adjust it by subtracting 360
        if (x > 360) {
            x = x - 360;
        }
        // Increment the counter
        count++;
    }
    
    // Print the final count
    printf("%d", count);
    
    return 0;
}

