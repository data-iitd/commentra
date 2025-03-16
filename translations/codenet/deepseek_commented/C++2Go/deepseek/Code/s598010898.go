package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements

	a := make([]int, n)
	b := make([]int, n)
	sum := 0

	// Read n integers into array a
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Read n integers into array b
	for i := 0; i < n; i++ {
		fmt.Scan(&b[i])
		if a[i] - b[i] > 0 { // Check if a[i] is greater than b[i]
			sum += a[i] - b[i] // Add the difference to sum
		}
	}

	// Output the sum
	fmt.Println(sum)
}

