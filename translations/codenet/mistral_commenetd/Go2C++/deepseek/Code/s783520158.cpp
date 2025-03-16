#include <iostream> // Include the iostream library for input and output

int main() {
    // Declare three integer variables "a", "b", and "c"
    int a, b, c;

    // Read three integers from the standard input and assign them to the variables
    std::cin >> a >> b >> c;

    // Check if the difference between "b" and "a" is equal to the difference between "c" and "b"
    if (b - a == c - b) {
        // If the condition is true, print "YES" to the standard output
        std::cout << "YES" << std::endl;
    } else {
        // If the condition is false, print "NO" to the standard output
        std::cout << "NO" << std::endl;
    }

    // End of the code
    return 0;
}
