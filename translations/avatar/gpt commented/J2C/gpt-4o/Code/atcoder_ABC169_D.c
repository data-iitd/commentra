#include <stdio.h>
#include <math.h>

int main() {
    // Declare a variable to hold the input number
    long n;
    
    // Read a long integer input from the user
    scanf("%ld", &n);
    
    // Calculate the integer square root of n
    int sqrt_n = (int) sqrt(n);
    // Initialize the answer variable to count the number of prime factors
    int answer = 0;

    // Loop through all integers from 2 to the square root of n
    for (int i = 2; i <= sqrt_n; i++) {
        // Initialize a count for the number of times i divides n
        int count = 0;
        // While n is divisible by i, divide n by i and increment count
        while (n % i == 0) {
            n /= i;
            count++;
        }
        // For each count of prime factor i, calculate the number of unique factors
        for (int j = 1; count - j >= 0; j++) {
            count -= j;
            answer++;
        }
    }
    // If n is greater than 1, it means n is a prime number itself
    if (n > 1) {
        answer++;
    }
    // Print the total number of unique prime factors
    printf("%d\n", answer);

    return 0;
}

// <END-OF-CODE>
