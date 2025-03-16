#include <iostream>
#include <iomanip>

int main() {
    // Define the first hour and minute variables from user input
    int h1, m1;
    char colon; // to consume the ':' character
    std::cin >> h1 >> colon >> m1;

    // Add the hour to the minute value
    m1 += h1 * 60;

    // Define the second hour and minute variables from user input
    int h2, m2;
    std::cin >> h2 >> colon >> m2;

    // Add the hour to the minute value for the second set of variables
    m2 += h2 * 60;

    // Calculate the difference between the total minutes of the first and second sets of variables
    m2 = m1 - m2;

    // Calculate the remainder of the difference when divided by 1440 (24 hours * 60 minutes)
    m2 = (m2 + 1440) % 1440; // Ensure m2 is non-negative

    // Print the result in the format of hours and minutes
    std::cout << std::setw(2) << std::setfill('0') << m2 / 60 << ":"
              << std::setw(2) << std::setfill('0') << m2 % 60 << std::endl;

    return 0;
}

// <END-OF-CODE>
