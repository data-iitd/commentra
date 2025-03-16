#include <stdio.h>

int main() {
    int S, W;
    // Read the values of S and W from a single line of input
    scanf("%d %d", &S, &W);
    
    // Check if the value of W is greater than or equal to S
    // If true, print "unsafe"
    if (S <= W) {
        printf("unsafe\n");
    } else {
        printf("safe\n");
    }
    
    return 0;
}

// <END-OF-CODE>
