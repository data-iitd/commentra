
// Package main provides the entry point for the program.
//
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Dec 29 04:47:30 2018
//
package main

import "fmt"

func main() {
	// Declare and initialize three integer variables, A, B, and C, with values read from the standard input.
	var A, B, C int
	fmt.Scan(&A, &B, &C)

	// Check if the sum of A and B is greater than or equal to C.
	if A+B >= C {
		// If the condition is true, print "Yes" to the standard output.
		fmt.Println("Yes")
	} else {
		// If the condition is false, print "No" to the standard output.
		fmt.Println("No")
	}
}

