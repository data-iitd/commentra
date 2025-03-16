#include <stdio.h>

int main() {
    int a, b;
    
    // Read two integers from input
    scanf("%d %d", &a, &b);
    
    // Calculate the minimum of a and b
    int min_val = (a < b) ? a : b;
    
    // Calculate the maximum of a and b
    int max_val = (a > b) ? a : b;
    
    // Calculate the half of the difference between the maximum and minimum values
    int half_diff = (max_val - min_val) / 2;
    
    // Print the minimum value and the calculated half difference
    printf("%d %d\n", min_val, half_diff);
    
    return 0;
}

// <END-OF-CODE>
