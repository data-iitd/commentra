
#include <stdio.h>

int main() {
    int n, i, j;
    
    // Read an integer input from the user
    scanf("%d", &n);
    
    // Initialize two variables: 'i' starting from 1 and 'j' starting from n*n
    i = 1;
    j = n * n;
    
    // Loop until 'i' is less than 'j'
    while (i < j) {
        // Print the current values of 'i' and 'j'
        printf("%d %d\n", i, j);
        
        // Increment 'i' to move towards the center
        i++;
        
        // Decrement 'j' to move towards the center
        j--;
    }
    
    return 0;
}

