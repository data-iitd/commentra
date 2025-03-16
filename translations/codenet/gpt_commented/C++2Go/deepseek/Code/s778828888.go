package main

import (
	"fmt"
	"math"
)

func main() {
	var n, m, x int
	// Initialize an array to keep track of the presence of numbers (size 105 to accommodate possible values)
	a := make([]int, 105)
	
	// Read the values of n, m, and x from standard input
	fmt.Scan(&n, &m, &x)

	// Read m numbers from input and mark their presence in the array 'a'
	for i := 0; i < m; i++ {
		var temp int
		// Read a number and set the corresponding index in array 'a' to 1
		fmt.Scan(&temp)
		a[temp] = 1
	}

	// Initialize counters for the number of present elements to the right (ansr) and left (ansl) of x
	ansl := 0
	ansr := 0

	// Count how many numbers are present from x to n (right side)
	for i := x; i <= n; i++ {
		ansr += a[i] // Increment ansr if a[i] is 1 (indicating presence)
	}

	// Count how many numbers are present from x to 0 (left side)
	for i := x; i >= 0; i-- {
		ansl += a[i] // Increment ansl if a[i] is 1 (indicating presence)
	}

	// Output the minimum of the counts from both sides
	fmt.Println(int(math.Min(float64(ansl), float64(ansr))))
}

