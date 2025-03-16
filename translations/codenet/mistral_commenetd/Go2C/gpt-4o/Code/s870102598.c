#include <stdio.h>

int main() {
    // Declare and initialize three integer variables "a", "b", and "c"
    int a, b, c;
    
    // Read input values for a, b, and c
    scanf("%d %d %d", &a, &b, &c);

    // Check if the value of "c" is within the range of "a" and "b"
    if (c >= a && c <= b) {
        // If the condition is true, print "Yes"
        printf("Yes\n");
    } else {
        // If the condition is false, print "No"
        printf("No\n");
    }

    return 0;
}

// <END-OF-CODE>
