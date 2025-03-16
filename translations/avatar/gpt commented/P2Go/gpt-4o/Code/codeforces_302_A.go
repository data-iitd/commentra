package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	var input string
	fmt.Scan(&input)

	// Count the number of '-' characters in the input string
	sa := strings.Count(input, "-")

	// Calculate the minimum of the remaining characters (n - sa) and the count of '-' (sa)
	if n-sa < sa {
		sa = n - sa
	}

	// Initialize a slice to store results
	var ss []string

	// Loop m times to read pairs of integers a and b
	for i := 0; i < m; i++ {
		var a, b int
		fmt.Scan(&a, &b)

		// Calculate the difference b - a
		b -= a

		// Check if b is odd and less than or equal to double the count of '-'
		if b%2 == 1 && b <= sa*2 {
			ss = append(ss, "1\n")
		} else {
			ss = append(ss, "0\n")
		}
	}

	// Print the concatenated results from the slice
	fmt.Print(strings.Join(ss, ""))
}

// <END-OF-CODE>
