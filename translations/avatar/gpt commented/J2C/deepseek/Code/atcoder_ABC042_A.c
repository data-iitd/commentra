#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables to hold the input values
    int x, a, y;
    char buffer[100];
    
    // Read a line of input and split it into an array of strings
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d %d %d", &x, &a, &y);
    
    // Initialize a variable to hold the result, defaulting to "NO"
    char h[] = "NO";
    
    // Check if any of the numbers x, a, or y are either 5 or 7
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        // If the sum of x, a, and y equals 17, set the result to "YES"
        if (x + y + a == 17) {
            h[0] = 'Y';
            h[1] = 'E';
            h[2] = 'S';
        }
    }
    
    // Output the result
    printf("%s\n", h);
    
    return 0;
}
