package main

import (
	"fmt"
)

func main() {
	var r, g, b, n int // Initialize variables for red, green, blue colors and number of balls

	// Read input values from standard input
	fmt.Scan(&r, &g, &b, &n)

	ans := 0 // Initialize answer variable to zero

	// Check all possible combinations of red, green and blue balls to find the answer
	for i := 0; i <= n/r; i++ { // Iterate through all possible combinations of red balls
		for j := 0; j <= n/g; j++ { // Iterate through all possible combinations of green balls
			num := n - r*i - g*j // Calculate the number of blue balls needed to make up the total number of balls

			// Check if the number of blue balls is valid (non-negative and divisible by b)
			if num >= 0 && num%b == 0 {
				ans++ // Increment the answer if the current combination is valid
			}
		}
	}

	// Print the answer to the standard output
	fmt.Println(ans)

	// End of main function
}
