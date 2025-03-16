
// Package main provides the entry point for the program.
//
// File:  a.c
// Author: ymiyamoto
//
// Created on Sat Dec 29 04:47:30 2018
//
#include <stdio.h>

int main(int argc, char** argv) {
	// Declare and initialize three integer variables, A, B, and C, with values read from the standard input.
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);

	// Check if the sum of A and B is greater than or equal to C.
	if (A+B >= C) {
		// If the condition is true, print "Yes" to the standard output.
		printf("Yes\n");
	} else {
		// If the condition is false, print "No" to the standard output.
		printf("No\n");
	}
}

