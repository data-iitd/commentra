package main

import (
	"fmt"
)

func main() {
	// Declare three string variables A, B, and C
	var A, B, C string

	// Initialize the string variables A, B, and C using fmt.Scan
	fmt.Scan(&A, &B, &C)

	// Calculate the length of strings A and B
	la := len(A)
	lb := len(B)

	// Check if the last character of string A is the same as the first character of string B
	// and the last character of string B is the same as the first character of string C
	if A[la-1] == B[0] && B[lb-1] == C[0] {
		// If the condition is true, print YES
		fmt.Println("YES")
	} else {
		// If the condition is false, print NO
		fmt.Println("NO")
	}
}

// <END-OF-CODE>
