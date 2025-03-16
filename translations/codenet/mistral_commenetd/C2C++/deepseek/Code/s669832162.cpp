#include <iostream> // Include the iostream library for input/output operations

int main() { // Start of the main function
    int m1, d1, m2, d2; // Declare four integer variables to store months and days

    // Read four integers from the standard input
    std::cin >> m1 >> d1 >> m2 >> d2;

    // Check if the first two months are equal or not
    if (m1 != m2) {
        // If the months are not equal, print "1" to the standard output
        std::cout << "1" << std::endl;
    } else {
        // If the months are equal, print "0" to the standard output
        std::cout << "0" << std::endl;
    }
}
