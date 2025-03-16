// Package main provides
//
// File:  a.go
// Author: ymiyamoto
//
// Created on Sat Dec 29 04:47:30 2018
//
package main

import "fmt"

func main() {
	// Declare three integer variables A, B, and C
	var A, B, C int
	
	// Read input values for A, B, and C from the standard input
	fmt.Scan(&A, &B, &C)

	// Check if the sum of A and B is greater than or equal to C
	if A+B >= C {
		// If the condition is true, print "Yes"
		fmt.Println("Yes")
	} else {
		// If the condition is false, print "No"
		fmt.Println("No")
	}
}
