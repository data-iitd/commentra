package main

import (
	"fmt"
)

func main() {
	// Create a Scanner object to read input from the user
	var n, k int
	fmt.Scan(&n, &k)

	// Initialize variables to keep track of the last number and its consecutive occurrences
	l, c := 0, 1

	// Loop to read n numbers and count consecutive occurrences
	for i := 0; i < n; i++ {
		var a int
		fmt.Scan(&a)
		if a == l {
			c++ // Increment count if the current number is the same as the last
		} else {
			c = 1 // Reset count if the current number is different
		}
		l = a // Update the last number
	}

	// Check if the number of consecutive occurrences plus the threshold value is greater than n
	if c+k > n {
		fmt.Println(n - c) // Print the number of elements to remove
	} else {
		fmt.Println(-1) // Print -1 if it's not possible to satisfy the condition
	}
}

// <END-OF-CODE>
