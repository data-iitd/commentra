
package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	// Read the dimensions of the grid (n: number of rows, m: number of columns)

	c := make(map[int]bool)
	// Create a map 'c' to store the differences between the indices of 'S' and 'G' for each row.

	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)
		// Read the string for each row

		s1 := strings.Index(s, "S")
		// Find the index of 'S' in the string

		s2 := strings.Index(s, "G")
		// Find the index of 'G' in the string

		c[s1-s2] = true
		// Calculate the difference between the indices of 'S' and 'G' for each row.
		// Store the difference in the map 'c'.
	}

	var count int
	for k := range c {
		if k >= 0 {
			count++
		}
	}
	// Count the number of unique non-negative differences.

	if count == 0 {
		fmt.Println(-1)
	} else {
		fmt.Println(count)
	}
	// Print the number of unique non-negative differences.
	// If there is no non-negative difference, print '-1'.
}

