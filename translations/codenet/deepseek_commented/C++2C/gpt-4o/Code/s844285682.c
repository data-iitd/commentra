#include <stdio.h>

int main() {
    int a, b; // Declare two integer variables a and b
    
    scanf("%d", &a); // Take an integer input from the user and store it in variable a
    
    printf("%d:%d:%d\n", a / (60 * 60), (a % (60 * 60)) / 60, (a % (60 * 60)) % 60); // Calculate and output the hours, minutes, and seconds
    
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
