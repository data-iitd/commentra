#include <stdio.h>
#include <stdlib.h>

// Function to find the greatest common divisor (GCD) of two numbers
long long gcd(long long x, long long y) {
    // Base case: if x is smaller than y, swap x and y
    if (x < y) {
        long long temp = x;
        x = y;
        y = temp;
    }

    // Recursive case: find the remainder of x divided by y and repeat
    while (y > 0) {
        long long r = x % y;
        x = y;
        y = r;
    }

    // Return the GCD (the last non-zero value of x)
    return x;
}

// Function to find the least common multiple (LCM) of two numbers
long long lcm(long long x, long long y) {
    // Return the product of x and y divided by their GCD
    return x / gcd(x, y) * y;
}

// Function to calculate the factorial (kaijo) of a number
long long kaijo(long long k) {
    long long sum = 1;
    // Calculate the factorial by multiplying the number with all the numbers less than it
    for (long long i = 1; i <= k; ++i) {
        sum *= i;
        // Modulo the result by 1000000000+7 to keep the result within a certain range
        sum %= 1000000000 + 7;
    }
    // Return the result
    return sum;
}

// Function to find the larger of two numbers
long long lmax(long long s, long long t) {
    // Return the larger of the two numbers
    return (s > t) ? s : t;
}

// Function to find the smaller of two numbers
long long lmin(long long s, long long t) {
    // Return the smaller of the two numbers
    return (s < t) ? s : t;
}

// Main function
int main() {
    // Read the input values for n and k from the standard input
    int n, k;
    scanf("%d %d", &n, &k);

    // Initialize a variable to store the sum of the results
    long long sum = 0;

    // Iterate through all possible block sizes from 1 to n
    for (int b = 1; b <= n; b++) {
        // Calculate the number of blocks of size b that can fit into n+1
        int cnt = (n + 1) / b;

        // Calculate the remainder of n+1 when divided by b
        int md = (n + 1) % b;

        // Add the number of blocks of size b that cover k or more numbers to the sum
        sum += cnt * (b - k > 0 ? (b - k) : 0) + (md - k > 0 ? (md - k) : 0);

        // If k is 0, subtract 1 from the sum (since an empty block doesn't contribute to the sum)
        if (k == 0) sum--;
    }

    // Print the result to the standard output
    printf("%lld\n", sum);

    // Return 0 to indicate successful execution
    return 0;
}

// <END-OF-CODE>
