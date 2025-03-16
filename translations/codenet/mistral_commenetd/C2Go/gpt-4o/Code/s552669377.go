package main

import (
	"fmt"
)

func main() {
	var n, tmp int
	min := 1000000
	max := -1000000
	sum := 0

	fmt.Print("Enter the number of integers: ")
	fmt.Scan(&n)
	// Read the number of integers to be entered from the user

	for i := 0; i < n; i++ {
		fmt.Scan(&tmp)
		// Read the next integer from the user and store it in variable tmp
		if min > tmp {
			min = tmp
		}
		// If the current integer is smaller than the current minimum, update the minimum
		if max < tmp {
			max = tmp
		}
		// If the current integer is larger than the current maximum, update the maximum
		sum += tmp
		// Add the current integer to the sum
	}

	fmt.Printf("%d %d %d\n", min, max, sum)
	// Print the minimum, maximum, and sum of the entered integers
}

// <END-OF-CODE>
