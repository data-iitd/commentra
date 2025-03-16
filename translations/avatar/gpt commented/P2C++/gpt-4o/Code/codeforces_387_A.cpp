#include <iostream>
#include <iomanip>

int main() {
    // Read the first time input in 'hh:mm' format and split it into hours and minutes
    int h1, m1;
    char colon; // to consume the ':' character
    std::cin >> h1 >> colon >> m1;

    // Convert the first time into total minutes
    m1 += h1 * 60;

    // Read the second time input in 'hh:mm' format and split it into hours and minutes
    int h2, m2;
    std::cin >> h2 >> colon >> m2;

    // Convert the second time into total minutes
    m2 += h2 * 60;

    // Calculate the difference in minutes between the first and second time
    m2 = m1 - m2;

    // Ensure the result is within a 24-hour format by taking modulo 1440 (total minutes in a day)
    m2 = (m2 + 1440) % 1440; // Adding 1440 to handle negative values

    // Print the result in 'hh:mm' format, ensuring two digits for both hours and minutes
    std::cout << std::setw(2) << std::setfill('0') << (m2 / 60) << ":"
              << std::setw(2) << std::setfill('0') << (m2 % 60) << std::endl;

    return 0;
}

// <END-OF-CODE>
