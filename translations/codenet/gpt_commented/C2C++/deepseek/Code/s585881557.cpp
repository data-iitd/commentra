#include <iostream>

int main() {
    // Declare two integer variables h and r
    int h, r;

    // Read two integers from standard input
    std::cin >> h >> r;

    // Compare the value of r with -h
    if (r > -h) {
        // If r is greater than -h, print "1"
        std::cout << "1" << std::endl;
    }
    else if (r == -h) {
        // If r is equal to -h, print "0"
        std::cout << "0" << std::endl;
    }
    else {
        // If r is less than -h, print "-1"
        std::cout << "-1" << std::endl;
    }

    // Return 0 to indicate successful completion of the program
    return 0;
}
