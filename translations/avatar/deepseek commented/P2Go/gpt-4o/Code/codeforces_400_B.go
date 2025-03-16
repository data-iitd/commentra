package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m) // Read the dimensions of the grid (n: number of rows, m: number of columns)

	c := make(map[int]struct{}) // Use a map to store unique differences

	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s) // Read each row of the grid
		indexS := strings.Index(s, "S") // Find the index of 'S'
		indexG := strings.Index(s, "G") // Find the index of 'G'
		diff := indexS - indexG // Calculate the difference

		c[diff] = struct{}{} // Store the difference in the map
	}

	// Check if there is any negative difference in the map
	negativeFound := false
	for diff := range c {
		if diff < 0 {
			negativeFound = true
			break
		}
	}

	if negativeFound {
		fmt.Println(-1) // If there is a negative difference, print '-1'
	} else {
		fmt.Println(len(c)) // Otherwise, print the number of unique non-negative differences
	}
}

// <END-OF-CODE>
