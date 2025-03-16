#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from standard input
int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Main function
int main() {
    // Read two integers n and k from input
    int n = readInt();
    int k = readInt();
    
    // Check if n is divisible by k
    if (n % k == 0) {
        // If divisible, print 0
        printf("0\n");
    } else {
        // If not divisible, print 1
        printf("1\n");
    }
    
    return 0;
}
