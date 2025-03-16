#include <iostream>

int main() {
    // Declare and initialize three integer variables "a", "b", and "c"
    int a, b, c;
    std::cin >> a >> b >> c;

    // Check if the value of "c" is within the range of "a" and "b"
    if (c >= a && c <= b) {
        // If the condition is true, print "Yes" to the standard output
        std::cout << "Yes" << std::endl;
    } else {
        // If the condition is false, print "No" to the standard output
        std::cout << "No" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
