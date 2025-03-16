#include <iostream>
#include <iomanip>

int main() {
    int h1, m1, h2, m2;
    
    // Input first time
    char colon; // to consume the ':' character
    std::cin >> h1 >> colon >> m1;
    m1 += h1 * 60;

    // Input second time
    std::cin >> h2 >> colon >> m2;
    m2 += h2 * 60;

    // Calculate the difference in minutes
    m2 = m1 - m2;
    m2 %= 1440;

    // Output the result in HH:MM format
    std::cout << std::setw(2) << std::setfill('0') << (m2 / 60) << ":"
              << std::setw(2) << std::setfill('0') << (m2 % 60) << std::endl;

    return 0;
}

// <END-OF-CODE>
