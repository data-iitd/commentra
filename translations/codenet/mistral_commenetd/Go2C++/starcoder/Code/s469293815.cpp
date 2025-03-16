
// Package main provides the entry point for the program.
//
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sat Dec 29 04:47:30 2018
//
#include <iostream>

using namespace std;

int main() {
	// Declare and initialize three integer variables, A, B, and C, with values read from the standard input.
	int A, B, C;
	cin >> A >> B >> C;

	// Check if the sum of A and B is greater than or equal to C.
	if (A+B >= C) {
		// If the condition is true, print "Yes" to the standard output.
		cout << "Yes" << endl;
	} else {
		// If the condition is false, print "No" to the standard output.
		cout << "No" << endl;
	}
}

