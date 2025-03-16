
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Read the first string from the standard input
	a, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	// Remove the trailing newline character from the first string
	a = strings.TrimSuffix(a, "\n")
	// Calculate the length of the first string
	n := len(a)

	// Read the second string from the standard input
	b, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	// Remove the trailing newline character from the second string
	b = strings.TrimSuffix(b, "\n")
	// Calculate the length of the second string
	m := len(b)

	// Initialize a variable to store the minimum number of mismatches
	minMismatches := n + 1

	// Iterate over all possible starting positions in 'a' where 'b' can fit
	for i := 0; i <= n-m; i++ {
		// Initialize a variable to count the number of mismatches
		mismatches := 0

		// Compare the substring of 'a' with 'b' character by character
		for j := 0; j < m; j++ {
			// Increment the mismatch count if characters do not match
			if a[i+j]!= b[j] {
				mismatches++
			}
		}

		// Update the minimum number of mismatches found
		if mismatches < minMismatches {
			minMismatches = mismatches
		}
	}

	// Output the minimum number of mismatches
	fmt.Println(minMismatches)
}

