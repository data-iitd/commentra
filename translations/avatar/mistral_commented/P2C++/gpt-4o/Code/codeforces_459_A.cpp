#include <iostream>
#include <cmath>
#include <vector>

int main() {
    // Get user input
    std::string input;
    std::getline(std::cin, input);

    // Split the input into a vector of integers
    std::vector<int> l1;
    std::istringstream iss(input);
    int number;
    while (iss >> number) {
        l1.push_back(number);
    }

    // Assign the first two elements of the vector to x1, y1 and the last two elements to x2, y2
    int x1 = l1[0], y1 = l1[1];
    int x2 = l1[2], y2 = l1[3];

    // Calculate the denominator and numerator of the slope
    int denominator = x2 - x1;
    int numerator = y2 - y1;

    // Check if the denominator is zero
    if (denominator == 0) {
        // Calculate the distance between the two points and print the result
        int d = static_cast<int>(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
        int x4 = x1, x3 = x2, y3 = y2 + d, y4 = y1 + d;
        std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
    }
    // If the denominator is not zero, calculate the quotient
    else {
        double quotient = static_cast<double>(numerator) / denominator;

        // Check if the quotient is equal to 1 or -1
        if (quotient == 1 || quotient == -1) {
            // Swap the x and y coordinates of the two points and print the result
            int x4, x3, y3, y4;
            if (quotient == 1) {
                x4 = x2; x3 = x1; y3 = y1; y4 = y2;
            } else {
                x4 = x1; x3 = x2; y3 = y2; y4 = y1;
            }
            std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
        }
        // If the quotient is not 1 or -1, print -1
        else {
            std::cout << "-1" << std::endl;
        }
    }

    return 0;
}

// <END-OF-CODE>
