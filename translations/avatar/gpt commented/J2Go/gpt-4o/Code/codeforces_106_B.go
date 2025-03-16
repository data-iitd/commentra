package main

import (
	"fmt"
)

func main() {
	// Read the number of entries
	var n int
	fmt.Scan(&n)

	// Initialize a 2D slice to store the input values
	vec := make([][4]int, n)

	// Read input values into the 2D slice
	for i := 0; i < n; i++ {
		fmt.Scan(&vec[i][0], &vec[i][1], &vec[i][2], &vec[i][3]) // Read four values
	}

	// Initialize variables to track the best option
	ans := 500 // Default answer if no valid option is found
	ansprice := 20000 // Set a high initial price

	// Iterate through each entry to find the best option
	for i := 0; i < n; i++ {
		fl := 1 // Flag to check if the current entry is not dominated

		// Check if the current entry is dominated by any other entry
		for j := 0; j < n; j++ {
			if vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2] {
				fl = 0 // Set flag to 0 if dominated
			}
		}

		// If the current entry is not dominated, check its price
		if fl == 1 {
			if vec[i][3] < ansprice {
				ansprice = vec[i][3] // Update the best price found
				ans = i + 1 // Update the answer with the current index (1-based)
			}
		}
	}

	// Output the result
	fmt.Println(ans)
}

// <END-OF-CODE>
