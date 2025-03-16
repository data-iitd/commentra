#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
    // Read the input value for h
    int h;
    scanf("%d", &h);

    // Loop until h becomes 1
    while (h!= 1) {
        // If h is odd, decrement it by 1 to make it even
        if (h % 2!= 0) h--;
        
        // Divide h by 2
        h /= 2;
    }

    // Output the final answer incremented by 1
    printf("%d\n", h + 1);
}

