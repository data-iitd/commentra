#include <iostream>
#include <cmath>

int main() {
    int n, m;
    std::cin >> n >> m;

    // Calculate the value of x using the given formula
    int x = m * 1900 + (n - m) * 100;

    // Print the result using std::cout
    std::cout << x * static_cast<int>(std::pow(2.0, static_cast<double>(m))) << std::endl;

    return 0;
}

