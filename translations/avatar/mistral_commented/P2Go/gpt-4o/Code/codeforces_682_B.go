package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read the number of test cases 'n'
	var n int
	fmt.Scan(&n)

	// Read the list 'l' of length 'n' containing 'n' integers
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	// Sort the list 'l' in ascending order
	sort.Ints(l)

	// Initialize variable 'c' to 0
	c := 0

	// Iterate through the list 'l'
	for _, i := range l {
		// If the current element 'i' is greater than the previous count 'c', increment 'c' by 1
		if i > c {
			c++
		}
	}

	// Print the final result, which is the number of unique elements in the list 'l' plus 1
	fmt.Println(c + 1)
}

// <END-OF-CODE>
