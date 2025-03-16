#include <iostream>

int main() {
    // Declare variables to hold the month and day values for two dates
    int m1, d1, m2, d2;

    // Read input values for the two dates (month and day)
    std::cin >> m1 >> d1 >> m2 >> d2;

    // Compare the months of the two dates
    if (m1 != m2) 
        // If the months are different, print "1"
        std::cout << "1\n";
    else 
        // If the months are the same, print "0"
        std::cout << "0\n";

    return 0; // Return 0 to indicate successful completion of the program
}

