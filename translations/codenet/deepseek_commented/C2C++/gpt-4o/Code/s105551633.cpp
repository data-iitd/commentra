#include <iostream>
#include <cmath>

// Define a type alias for long long int
typedef long long int int64;

// Define macros for maximum, minimum, and absolute value
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

// Function to count the number of digits in a number
int digit(int64 n) {
    int res = 0;
    while (n > 0) {
        res++;
        n /= 10;
    }
    return res;
}

// Main logic of the program
void run() {
    int64 n;
    std::cin >> n;
    int min = digit(n);
    for (int i = 1; (int64)i * i <= n; i++) {
        if (n % i != 0) continue;
        int64 a = i;
        int64 b = n / i;
        min = MIN(min, MAX(digit(a), digit(b)));
    }
    std::cout << min << std::endl;
}

// Main function
int main() {
    run();
    return 0;
}

// <END-OF-CODE>
