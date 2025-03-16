#include <stdio.h>

int main() {
    // Declare three integer variables to hold the input values
    int a, b, c;
    
    // Read three integer values from the standard input and assign them to a, b, and c
    scanf("%d %d %d", &a, &b, &c);
    
    // Check if the difference between b and a is equal to the difference between c and b
    if (b - a == c - b) {
        // If the condition is true, print "YES"
        printf("YES\n");
    } else {
        // Otherwise, print "NO"
        printf("NO\n");
    }
    
    return 0;
}

// <END-OF-CODE>
