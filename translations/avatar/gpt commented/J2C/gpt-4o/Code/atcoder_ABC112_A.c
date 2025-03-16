#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the first input as an integer
    int n;
    scanf("%d", &n);
    
    // Check if the input is 1
    if (n == 1) {
        // If the input is 1, print "Hello World"
        printf("Hello World\n");
    } else {
        // If the input is not 1, read two more integers
        int a, b;
        scanf("%d %d", &a, &b);
        // Print their sum
        printf("%d\n", a + b);
    }

    return 0;
}

// <END-OF-CODE>
