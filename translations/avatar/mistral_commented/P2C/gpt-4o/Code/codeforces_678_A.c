#include <stdio.h>

int main() {
    int vamshi, z;
    
    // Read a line of text from the standard input stream and convert it into integers
    scanf("%d %d", &vamshi, &z);
    
    // Calculate the number of complete divisions of z into vamshi
    // Add 1 to account for the remainder
    // Multiply the result by z
    printf("%d\n", (vamshi / z + 1) * z);
    
    return 0;
}

// <END-OF-CODE>
