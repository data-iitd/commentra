#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c;
    
    // Read two integers from standard input
    scanf("%d %d", &a, &b);
    
    // Calculate the value of c based on the formula: c = a - b * 2
    c = a - b * 2;
    
    // If c is negative, set it to 0
    if (c < 0) c = 0;
    
    // Output the final value of c
    printf("%d\n", c);
    
    return 0;
}
