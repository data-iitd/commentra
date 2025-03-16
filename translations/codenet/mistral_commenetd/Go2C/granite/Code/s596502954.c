

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Comment: Reads the first three integers from the input
    int a = 0, b = 0, c = 0;
    scanf("%d %d %d", &a, &b, &c);

    // Check if the condition is true
    if (a + b >= c) {
        // If true, print "Yes" to the output
        printf("Yes\n");
    } else {
        // If false, print "No" to the output
        printf("No\n");
    }

    // End of code
    
    return 0;
}