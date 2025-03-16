
package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	// Read two integers n and m from input

	sa := strings.Count(string(n), "-")
	// Count the number of '-' characters in the input

	sa = int(math.Min(float64(n-sa), float64(sa)))
	// Set sa to the minimum of n - sa and sa, possibly normalizing sa

	ss := make([]string, 0)
	// Initialize an empty list to store results

	for i := 0; i < m; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		// Read two integers a and b in each iteration of the loop

		b -= a
		// Subtract a from b

		if b%2 == 0 && b <= sa*2 {
			// Check if b is odd and within certain bounds
			ss = append(ss, "1\n")
			// Append "1\n" to ss if condition is met
		} else {
			ss = append(ss, "0\n")
			// Append "0\n" to ss otherwise
		}
	}

	fmt.Print(strings.Join(ss, ""))
	// Join and print the contents of ss
}

