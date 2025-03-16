#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    // Reading the number of inputs
    scanf("%d", &n);
    
    // Processing the input based on the value of n
    if (n == 1) {
        // Outputting "Hello World" if n is 1
        printf("Hello World\n");
    } else {
        // Reading two integers and calculating their sum if n is not 1
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }
    
    return 0;
}

// <END-OF-CODE>
