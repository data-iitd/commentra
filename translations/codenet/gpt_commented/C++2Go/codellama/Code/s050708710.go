package main

import (
	"fmt"
)

func main() {
	// Declare variables for the number of red, green, blue items and the total number of items
	var r, g, b, n int

	// Input the values for red, green, blue items and total items
	fmt.Scan(&r, &g, &b, &n)

	// Initialize the answer counter to zero
	ans := 0

	// Iterate over the possible counts of red items (i)
	for i := 0; i <= n / r; i++ {
		// Iterate over the possible counts of green items (j)
		for j := 0; j <= n / g; j++ {
			// Calculate the remaining items after selecting i red and j green items
			num := n - r*i - g*j

			// Check if the remaining items can be exactly filled with blue items
			if num >= 0 && num%b == 0 {
				// If valid, increment the answer counter
				ans++
			}
		}
	}

	// Output the total number of valid combinations found
	fmt.Println(ans)
}

