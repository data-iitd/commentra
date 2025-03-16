#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

int main() {
    int h1, m1, h2, m2;

    // Read the first time input in 'hh:mm' format and split it into hours and minutes
    std::string time1;
    std::getline(std::cin, time1);
    std::stringstream ss1(time1);
    char colon;
    ss1 >> h1 >> colon >> m1;

    // Convert the first time into total minutes
    m1 += h1 * 60;

    // Read the second time input in 'hh:mm' format and split it into hours and minutes
    std::string time2;
    std::getline(std::cin, time2);
    std::stringstream ss2(time2);
    ss2 >> h2 >> colon >> m2;

    // Convert the second time into total minutes
    m2 += h2 * 60;

    // Calculate the difference in minutes between the first and second time
    m2 = m1 - m2;

    // Ensure the result is within a 24-hour format by taking modulo 1440 (total minutes in a day)
    m2 %= 1440;

    // Print the result in 'hh:mm' format, ensuring two digits for both hours and minutes
    std::cout << std::setw(2) << std::setfill('0') << m2 / 60 << ":"
              << std::setw(2) << std::setfill('0') << m2 % 60 << std::endl;

    return 0;
}
