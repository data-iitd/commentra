#include <iostream>
#include <cmath>
#include <vector>

int main() {
    // Step 1: Take input from the user and split it into a vector of integers
    std::string given;
    std::getline(std::cin, given);
    std::istringstream iss(given);
    std::vector<int> l1;
    int num;

    while (iss >> num) {
        l1.push_back(num);
    }

    // Step 2: Assign the values to variables x1, y1, x2, and y2
    int x1 = l1[0];
    int y1 = l1[1];
    int x2 = l1[2];
    int y2 = l1[3];

    // Step 3: Check if the denominator is not zero to calculate the quotient
    int denominator = x2 - x1;
    int numerator = y2 - y1;
    double quotient;

    if (denominator != 0) {
        quotient = static_cast<double>(numerator) / denominator;
    }

    // Step 4: If the numerator is zero, calculate the distance and print the coordinates of two points
    if (numerator == 0) {
        int d = static_cast<int>(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
        int x4 = x1;
        int x3 = x2;
        int y3 = y2 + d;
        int y4 = y1 + d;
        std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
    }
    // Step 5: If the denominator is zero, print the coordinates of two points based on the distance calculated
    else if (denominator == 0) {
        int y4 = y2;
        int y3 = y1;
        int d = static_cast<int>(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
        int x4 = x1 + d;
        int x3 = x2 + d;
        std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
    }
    // Step 6: If the quotient is 1 or -1, swap the coordinates and print them
    else if (quotient == 1) {
        int x4 = x2;
        int x3 = x1;
        int y4 = y1;
        int y3 = y2;
        std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
    } else if (quotient == -1) {
        int x4 = x1;
        int x3 = x2;
        int y4 = y2;
        int y3 = y1;
        std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
    }
    // Step 7: If none of the above conditions are met, print -1
    else {
        std::cout << "-1" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
