// File: a.cpp
// Author: ymiyamoto
//
// Created on Sat Dec 29 04:47:30 2018
//
#include <iostream>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    // Read three integers from standard input
    // A, B, and C will store these values

    if (A + B >= C) {
        // Check if the sum of A and B is greater than or equal to C
        std::cout << "Yes" << std::endl;
    } else {
        // If the sum is less than C, print "No"
        std::cout << "No" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
