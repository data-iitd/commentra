#include <stdio.h>

int main() {
    // Declare three integer variables a, b, and c
    int a, b, c;
    
    // Read input values for a, b, and c from the user
    scanf("%d %d %d", &a, &b, &c);

    // Check if c is within the range [a, b]
    if (c >= a && c <= b) {
        // If c is within the range, print "Yes"
        printf("Yes\n");
    } else {
        // If c is outside the range, print "No"
        printf("No\n");
    }

    return 0;
}
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
// <END-OF-CODE>
