
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Declare three string variables to store the input strings
	var A, B, C string

	// Create a scanner to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Read three strings from the user, separated by spaces
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	A, B, C = parts[0], parts[1], parts[2]

	// Calculate the lengths of strings A and B
	la, lb := len(A), len(B)

	// Check if the last character of A matches the first character of B
	// and if the last character of B matches the first character of C
	if A[la-1] == B[0] && B[lb-1] == C[0] {
		// If both conditions are true, print "YES"
		fmt.Println("YES")
	} else {
		// Otherwise, print "NO"
		fmt.Println("NO")
	}
}

