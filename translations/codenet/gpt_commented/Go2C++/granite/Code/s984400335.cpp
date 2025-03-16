
#include <iostream>
#include <algorithm>

// min function takes a variable number of integer arguments and returns the minimum value among them.
int min(int a, int b) {
    return std::min(a, b);
}

int main() {
    // Declare variables to hold input values
    int n, a, b;
    // Read three integers from standard input
    std::cin >> n >> a >> b;

    // Calculate the minimum of n*a and b, and print the result
    std::cout << min(n*a, b) << std::endl;

    return 0;
}

