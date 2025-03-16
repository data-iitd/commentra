#include <iostream>
#include <cmath>

int main() {
    // Declare and initialize two integer variables n and m using std::cin
    int n, m;
    std::cin >> n >> m;

    // Calculate the value of x using the given formula
    int x = m * 1900 + (n - m) * 100;

    // Print the result using std::cout
    std::cout << x * static_cast<int>(pow(2.0, m)) << std::endl;

    return 0;
}

// <END-OF-CODE>
