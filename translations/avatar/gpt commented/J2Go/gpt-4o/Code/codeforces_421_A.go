package main

import (
	"fmt"
)

func main() {
	// Create a scanner to read input from the console
	var n, a, b int

	// Read the values for n, a, and b from the input
	fmt.Scan(&n, &a, &b)

	// Initialize two slices to store the elements of the two lists
	list1 := make(map[int]struct{})
	list2 := make([]int, b)

	// Read 'a' integers into list1
	for i := 0; i < a; i++ {
		var num int
		fmt.Scan(&num)
		list1[num] = struct{}{}
	}

	// Read 'b' integers into list2
	for i := 0; i < b; i++ {
		fmt.Scan(&list2[i])
	}

	// Iterate from 0 to n-1 to check the presence of each index in list1
	for i := 0; i < n; i++ {
		// If the current index + 1 is in list1, print 1
		if _, exists := list1[i+1]; exists {
			fmt.Print(1, " ")
		} else {
			// Otherwise, print 2
			fmt.Print(2, " ")
		}
	}
}

// <END-OF-CODE>
