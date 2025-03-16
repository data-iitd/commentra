#include <stdio.h>
#include <math.h>

int main() {
    // Declare variables to store the number of successful and failed runs
    int n, m;
    
    // Read the number of successful and failed runs from the standard input
    scanf("%d %d", &n, &m);
    
    // Calculate the total time in milliseconds for the successful and failed runs
    int x = m * 1900 + (n - m) * 100;
    
    // Print the result of the expression (total time * 2^m)
    printf("%d\n", x * (int)pow(2.0, (double)m));
    
    return 0;
}

