// ABC 152-D
// 2020.1.19 bal4u

#include <iostream>
#include <vector>

#define gc() getchar_unlocked()

int in() {   // Non-negative integer input
    int n = 0, c = gc();
    do {
        n = 10 * n + (c & 0xf); // Multiply the digit by 10 and add
    } while ((c = gc()) >= '0'); // Read the next digit
    return n;
}

std::vector<int> f1(100, 0), f2(100, 0);

void calc(int n) { // Function to process n
    int k = n % 10; // Get the last digit of n
    while (n >= 10) { // Divide n by 10 while it is greater than or equal to 10
        n /= 10;
    }
    ++f1[10 * k + n]; // Increment f1 array at [10*k+n]
    ++f2[n * 10 + k]; // Increment f2 array at [n*10+k]
}

int main() {
    int i, N, ans;

    N = in(); // Input the number of entries
    while (N) { // While N is not zero
        calc(N); // Call the calc function
        N--; // Decrement N by 1
    }

    ans = 0; // Initialize the answer
    for (i = 0; i < 100; ++i) { // Loop through f1 and f2 arrays to calculate the answer
        ans += f1[i] * f2[i];
    }
    std::cout << ans << std::endl; // Output the answer
    return 0;
}

// <END-OF-CODE>
