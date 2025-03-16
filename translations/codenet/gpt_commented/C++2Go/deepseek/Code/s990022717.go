package main

import (
	"fmt"
)

func main() {
	// Declare variables for input
	var n, k, x, y int
	
	// Read input values: n (total items), k (threshold), x (cost for first k items), y (cost for items beyond k)
	fmt.Scan(&n, &k, &x, &y)
	
	// Initialize sum to accumulate total cost
	sum := 0

	// Loop through each item from 1 to n
	for i := 1; i <= n; i++ {
		// If the current item index exceeds k, add cost y; otherwise, add cost x
		if i > k {
			sum += y // Cost for items beyond the threshold
		} else {
			sum += x // Cost for items within the threshold
		}
	}

	// Output the total calculated cost
	fmt.Println(sum)
}

