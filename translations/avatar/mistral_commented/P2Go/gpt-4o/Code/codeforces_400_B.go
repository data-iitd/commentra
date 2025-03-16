package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read input
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize a map to simulate a set
	c := make(map[int]struct{})

	// Populate set c with differences between indices of 'S' and 'G' in each string
	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)

		// Find the indices of 'S' and 'G' in the current string
		indexS := strings.Index(s, "S")
		indexG := strings.Index(s, "G")

		// Calculate the difference and add it to the map
		difference := indexS - indexG
		c[difference] = struct{}{}
	}

	// Check if there is any negative number in map c and print accordingly
	negativeFound := false
	for key := range c {
		if key < 0 {
			negativeFound = true
			break
		}
	}

	if negativeFound {
		fmt.Println(-1)
	} else {
		fmt.Println(len(c))
	}
}

// <END-OF-CODE>
