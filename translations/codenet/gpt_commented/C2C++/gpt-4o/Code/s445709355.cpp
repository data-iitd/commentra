// ABC 152-D
// 2020.1.19 bal4u

#include <iostream>
#include <vector>

// Fast input function to read a character from standard input
#define gc() getchar_unlocked()

// Function to read a non-negative integer from input
int in() {   // 非負整数の入力
    int n = 0, c = gc(); // Initialize n to 0 and read the first character
    // Loop to construct the integer from characters until a non-digit is encountered
    do n = 10 * n + (c & 0xf); while ((c = gc()) >= '0');
    return n; // Return the constructed integer
}

// Arrays to store frequency counts for two different calculations
int f1[100] = {0}, f2[100] = {0};

// Function to calculate frequency counts based on the input number
void calc(int n) {
    int k = n % 10; // Extract the last digit of n
    // Reduce n to its first digit by continuously dividing by 10
    while (n >= 10) n /= 10;
    // Update frequency counts for combinations of first and last digits
    ++f1[10 * k + n];
    ++f2[n * 10 + k];
}

int main() {
    int i, N, ans; // Declare variables for iteration, input number, and answer
    
    // Read the total number of inputs
    N = in();
    // Process each number from N down to 1
    while (N) calc(N--);

    ans = 0; // Initialize answer to 0
    // Calculate the final answer by summing the products of corresponding frequencies
    for (i = 0; i < 100; ++i) ans += f1[i] * f2[i];
    // Output the final answer
    std::cout << ans << std::endl;
    return 0; // Return success
}

// <END-OF-CODE>
