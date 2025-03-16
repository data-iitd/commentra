
#include <stdio.h>

int main() {
    int n, i, j;
    
    // Read an integer value from standard input and store it in the variable 'n'
    scanf("%d", &n);
    
    // Initialize the variables 'i' and 'j' with initial values 1 and 'n * n' respectively
    i = 1;
    j = n * n;
    
    // Start the while loop with the condition 'i < j'
    while (i < j) {
        // Print the current values of 'i' and 'j' on the standard output
        printf("%d %d\n", i, j);
        
        // Increment the value of 'i' by 1 in each iteration of the loop
        i++;
        
        // Decrement the value of 'j' by 1 in each iteration of the loop
        j--;
    }
    
    return 0;
}
