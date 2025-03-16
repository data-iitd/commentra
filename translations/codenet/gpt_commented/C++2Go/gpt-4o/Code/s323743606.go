package main

import (
	"fmt"
)

func main() {
	// Declare a map to store the minimum price for each weight
	m := make(map[int]int)

	// Iterate over possible quantities of items weighing 200 units
	for i := 0; i*200 < 5001; i++ {
		// Iterate over possible quantities of items weighing 300 units
		for j := 0; j*300 < 5001; j++ {
			// Iterate over possible quantities of items weighing 500 units
			for k := 0; k*500 < 5001; k++ {
				// Calculate the total weight based on the quantities of items
				w := i*200 + j*300 + k*500

				// Calculate the price based on the quantities of items
				p := (i/5)*5*380*0.8 + (i%5)*380 +
					(j/4)*4*550*0.85 + (j%4)*550 +
					(k/3)*3*850*0.88 + (k%3)*850

				// Update the map with the minimum price for the calculated weight
				if existingPrice, exists := m[w]; exists {
					m[w] = min(existingPrice, p) // If weight already exists, take the minimum price
				} else {
					m[w] = p // If weight does not exist, set the price
				}
			}
		}
	}

	// Read input weights and output the corresponding minimum prices
	var n int
	for {
		if _, err := fmt.Scan(&n); err != nil || n == 0 {
			break
		}
		fmt.Println(m[n]) // Output the minimum price for the given weight
	}
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
