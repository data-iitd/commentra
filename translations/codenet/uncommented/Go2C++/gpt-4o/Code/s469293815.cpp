// Package main provides
//
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sat Dec 29 04:47:30 2018
//
#include <iostream>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    if (A + B >= C) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
