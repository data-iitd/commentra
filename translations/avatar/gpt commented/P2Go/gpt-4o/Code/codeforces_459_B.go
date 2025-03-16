package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read an integer input for the number of elements
	var n int
	fmt.Scan(&n)

	// Read a line of input, split it into individual strings, convert them to integers, and store them in a slice
	l1 := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l1[i])
	}

	// Sort the slice of integers in ascending order
	sort.Ints(l1)

	// Assign the maximum value in the slice to variable 'a'
	a := l1[n-1]

	// Assign the minimum value in the slice to variable 'b'
	b := l1[0]

	// Check if the maximum and minimum values are the same
	if a == b {
		// If they are the same, the difference is zero and the number of pairs is n choose 2
		fmt.Println(a-b, (n*(n-1))/2)
	} else {
		// Count occurrences of the maximum value 'a' in the slice
		ac := 0
		for _, value := range l1 {
			if value == a {
				ac++
			}
		}

		// Count occurrences of the minimum value 'b' in the slice
		bc := 0
		for _, value := range l1 {
			if value == b {
				bc++
			}
		}

		// Calculate the difference between the maximum and minimum values, and the product of their counts
		fmt.Println(a-b, ac*bc)
	}
}

// <END-OF-CODE>
