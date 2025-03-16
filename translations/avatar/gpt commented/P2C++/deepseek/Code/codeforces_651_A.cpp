#include <iostream>
#include <algorithm> // for std::max

int main() {
    int x, y;
    std::cin >> x >> y;

    // Calculate the maximum value based on the formula and print it
    // The formula computes x + y - 3 and adjusts based on the difference between y and x
    // It ensures the result is not negative by taking the maximum with 0
    int result = std::max(x + y - 3 + ((y - x) % 3 != 0), 0);
    std::cout << result << std::endl;

    return 0;
}
