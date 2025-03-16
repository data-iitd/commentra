package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var n int
	var a, b []int
	var sum int

	// Read the number of elements
	fmt.Scan(&n)

	// Input the first array 'a'
	a = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Input the second array 'b' and calculate the sum of positive differences
	b = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&b[i])
		if a[i] - b[i] > 0 {
			sum += a[i] - b[i]
		}
	}

	// Output the final sum of positive differences
	fmt.Println(sum)
}

