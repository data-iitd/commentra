#include <iostream>
#include <algorithm> // for std::min and std::max

int main() {
    int a, b;
    
    // Get user input as two integers
    std::cin >> a >> b;

    // Find the minimum value between 'a' and 'b'
    int min_value = std::min(a, b);

    // Find the maximum value between 'a' and 'b'
    int max_value = std::max(a, b);

    // Print the minimum value and the average of the difference between minimum and maximum values
    std::cout << min_value << " " << (max_value - min_value) / 2 << std::endl;

    return 0;
}

// <END-OF-CODE>
