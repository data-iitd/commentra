#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::vector<int> l1;
    int num;

    // Read the input and split it into a list of integers
    while (ss >> num) {
        l1.push_back(num);
    }

    // Assign the first four integers to coordinates (x1, y1) and (x2, y2)
    int x1 = l1[0];
    int y1 = l1[1];
    int x2 = l1[2];
    int y2 = l1[3];

    // Calculate the denominator and numerator for slope calculation
    int denominator = x2 - x1;
    int numerator = y2 - y1;

    // Check if the line is not vertical
    if (denominator != 0) {
        double quotient = static_cast<double>(numerator) / denominator;  // Calculate the slope of the line

        // Check if the line is horizontal
        if (numerator == 0) {
            // Calculate the distance between the two points
            int d = static_cast<int>(std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2)));
            // Set new coordinates for the points shifted vertically
            int x4 = x1;
            int x3 = x2;
            int y3 = y2 + d;
            int y4 = y1 + d;
            // Print the new coordinates
            std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
        }

        // Check if the line is vertical
        else if (denominator == 0) {
            // Set y-coordinates to the original y-values
            int y4 = y2;
            int y3 = y1;
            // Calculate the distance between the two points
            int d = static_cast<int>(std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2)));
            // Set new coordinates for the points shifted horizontally
            int x4 = x1 + d;
            int x3 = x2 + d;
            // Print the new coordinates
            std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
        }

        // Check if the slope is 1 (45 degrees)
        else if (quotient == 1) {
            // Set new coordinates for the points
            int x4 = x2;
            int x3 = x1;
            int y4 = y1;
            int y3 = y2;
            // Print the new coordinates
            std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
        }

        // Check if the slope is -1 (-45 degrees)
        else if (quotient == -1) {
            // Set new coordinates for the points
            int x4 = x1;
            int x3 = x2;
            int y4 = y2;
            int y3 = y1;
            // Print the new coordinates
            std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
        }

        // If none of the conditions are met, print -1
        else {
            std::cout << -1 << std::endl;
        }
    }

    // If none of the conditions are met, print -1
    else {
        std::cout << -1 << std::endl;
    }

    return 0;
}
