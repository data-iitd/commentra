package main

import (
	"fmt"
)

func main() {
	var xxs []string
	var x, t, a, b, da, db int

	// Read input and split it into a slice of strings
	fmt.Scan(&xxs)

	// Convert the input values to integers
	x = int(xxs[0][0] - '0')
	t = int(xxs[1][0] - '0')
	a = int(xxs[2][0] - '0')
	b = int(xxs[3][0] - '0')
	da = int(xxs[4][0] - '0')
	db = int(xxs[5][0] - '0')

	// Define the main function to perform the logic
	main()

	// Check if the value of x is 0
	if x == 0 {
		fmt.Println("YES")
		return
	}

	// Calculate the maximum number of times a and b can be decremented within the time limit t
	a_time := min(a/da, t-1)
	b_time := min(b/db, t-1)

	// Iterate over all possible combinations of decrements for a and b within their respective limits
	for i := 0; i <= a_time; i++ {
		for j := 0; j <= b_time; j++ {
			// Check if either a or b (or their sum) equals x
			if a-da*i == x || b-db*j == x {
				fmt.Println("YES")
				return
			}
			if (a-da*i)+(b-db*j) == x {
				fmt.Println("YES")
				return
			}
		}
	}

	// Print "NO" if no combination results in x
	fmt.Println("NO")
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

