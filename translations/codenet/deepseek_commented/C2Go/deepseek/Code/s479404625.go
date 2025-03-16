package main

import (
	"fmt"
	"strings"
)

func main() {
	// Declare character arrays to store three strings
	var A, B, C string

	// Read three strings from the user, separated by spaces
	fmt.Scan(&A, &B, &C)

	// Calculate the lengths of strings A and B
	la := len(A)
	lb := len(B)

	// Check if the last character of A matches the first character of B
	// and if the last character of B matches the first character of C
	if A[la - 1] == B[0] && B[lb - 1] == C[0] {
		// If both conditions are true, print "YES"
		fmt.Println("YES")
	} else {
		// Otherwise, print "NO"
		fmt.Println("NO")
	}
}

