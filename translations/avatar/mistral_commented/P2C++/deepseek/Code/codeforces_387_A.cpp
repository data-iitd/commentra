#include <iostream>
#include <string>
#include <sstream>

int main() {
    int h1, m1, h2, m2;

    // Define the first hour and minute variables from user input
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss1(input);
    char colon;
    ss1 >> h1 >> colon >> m1;

    // Add the hour to the minute value
    m1 += h1 * 60;

    // Define the second hour and minute variables from user input
    std::getline(std::cin, input);
    std::stringstream ss2(input);
    ss2 >> h2 >> colon >> m2;

    // Add the hour to the minute value for the second set of variables
    m2 += h2 * 60;

    // Calculate the difference between the total minutes of the first and second sets of variables
    m2 = m1 - m2;

    // Calculate the remainder of the difference when divided by 1440 (24 hours * 60 minutes)
    m2 %= 1440;

    // Print the result in the format of hours and minutes
    std::cout << std::to_string(m2 / 60).insert(0, 2 - std::to_string(m2 / 60).length(), '0') + ":" + std::to_string(m2 % 60).insert(0, 2 - std::to_string(m2 % 60).length(), '0') << std::endl;

    return 0;
}
