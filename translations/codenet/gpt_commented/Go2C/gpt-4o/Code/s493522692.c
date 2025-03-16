#include <stdio.h>
#include <stdlib.h>
#include <math.h>

<<<<<<< HEAD
// Utility functions for mathematical operations
=======
// Utility functions for input and mathematical operations
>>>>>>> 98c87cb78a (data updated)

// maxInt returns the maximum of two integers
int maxInt(int a, int b) {
    return (a > b) ? a : b;
}

// minInt returns the minimum of two integers
int minInt(int a, int b) {
    return (a < b) ? a : b;
}

<<<<<<< HEAD
// gcd calculates the greatest common divisor of two integers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// lcm calculates the least common multiple of two integers
int lcm(int x, int y) {
    return x * (y / gcd(x, y));
=======
// absInt returns the absolute value of an integer
int absInt(int a) {
    return (a >= 0) ? a : -a;
}

// powInt calculates p raised to the power of q
int powInt(int p, int q) {
    return (int)pow((double)p, (double)q);
}

// isPrime checks if a number is prime
int isPrime(int x) {
    if (x <= 1) return 0;
    if (x == 2) return 1;
    if (x % 2 == 0) return 0;

    int rootx = (int)sqrt((double)x);
    for (int i = 3; i <= rootx; i += 2) {
        if (x % i == 0) return 0;
    }
    return 1;
>>>>>>> 98c87cb78a (data updated)
}

// Main function
int main() {
    int N, M;
    scanf("%d %d", &N, &M); // Read the number of 'S' and 'c'
    
    int tmp = minInt(N, M / 2); // Calculate the minimum of N and half of M
    int ans = 0;
    ans += tmp; // Add the temporary value to the answer
    N -= tmp; // Decrease N by the temporary value
    M -= tmp * 2; // Decrease M by twice the temporary value
    
    // Output the final answer, which includes the remaining M divided by 4
    printf("%d\n", ans + M / 4);
    
    return 0;
}

// <END-OF-CODE>
