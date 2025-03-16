#include <iostream>
#include <iomanip>

int main() {
    // Taking input in the format of 'HH:MM' and splitting it into hours and minutes
    int h1, m1;
    char colon; // to consume the ':' character
    std::cin >> h1 >> colon >> m1;

    // Converting hours to minutes and adding it to the minutes part
    m1 += h1 * 60;

    // Taking another input in the same format and converting it into total minutes since midnight
    int h2, m2;
    std::cin >> h2 >> colon >> m2;
    m2 += h2 * 60;

    // Calculating the difference in total minutes between the two times
    m2 = m1 - m2;

    // Ensuring the result is within a 24-hour period by using modulo operation
    m2 = (m2 + 1440) % 1440; // Adding 1440 to handle negative values

    // Printing the result in 'HH:MM' format
    std::cout << std::setw(2) << std::setfill('0') << (m2 / 60) << ":"
              << std::setw(2) << std::setfill('0') << (m2 % 60) << std::endl;

    return 0;
}

// <END-OF-CODE>
