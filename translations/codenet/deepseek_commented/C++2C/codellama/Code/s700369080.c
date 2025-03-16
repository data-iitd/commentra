#include <stdio.h> // Include necessary headers for input and output operations

int main(){
    long long x1, x2, y1, y2; // Define four long long integers
    scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2); // Read four long long integers from the standard input

    // Calculate the differences between the coordinates
    const long long dx = x2 - x1, dy = y2 - y1;

    // Compute the new coordinates based on the differences
    long long x3 = x2 - dy, y3 = y2 + dx;
    long long x4 = x1 - dy, y4 = y1 + dx;

    // Output the new coordinates
    printf("%lld %lld %lld %lld\n", x3, y3, x4, y4);
    return 0;
}

