#include <iostream>

int main() {
    // Declare three integer variables A, B, and C
    int A, B, C;

    // Read three integers from the standard input using cin
    std::cin >> A >> B >> C;

    // Check if A is less than C and C is less than B
    if (A < C && C < B) {
        // If condition is true, print "Yes" to the standard output
        std::cout << "Yes" << std::endl;
    } // End of first if block

    // Else if condition checks if A is greater than C and C is greater than B
    else if (A > C && C > B) {
        // If condition is true, print "Yes" to the standard output
        std::cout << "Yes" << std::endl;
    } // End of second if block

    // Else condition is executed when neither first nor second condition is true
    else {
        // If condition is false, print "No" to the standard output
        std::cout << "No" << std::endl;
    } // End of else block

    return 0; // End of main function
} // End of main function
// <END-OF-CODE>
