package main

import "fmt"

func main() {
	// Declare variables to hold the number of operations (n) and the sequence of operations (s)
	var n int
	var s string
	
	// Read input values for n and s from the standard input
	fmt.Scan(&n, &s)

	// Initialize variables to track the maximum count and the current count
	max := 0
	cnt := 0
	
	// Iterate over each character in the string s
	for _, r := range s {
		// Increment count for 'I' and decrement for any other character
		if r == 'I' {
			cnt++
		} else {
			cnt--
		}

		// Update max if the current count exceeds the previously recorded maximum
		if cnt > max {
			max = cnt
		}
	}

	// Print the maximum count achieved during the iterations
	fmt.Println(max)
}
