#include <stdio.h>

int main() {
    // Declare an integer variable 'a' to store the user input
    int a;
    
    // Read an integer input from the user and store it in 'a'
    scanf("%d", &a);
    
    // Print the result of the expression 'a + a*a + a*a*a'
    printf("%d\n", a + a*a + a*a*a);
    
    return 0;
}

