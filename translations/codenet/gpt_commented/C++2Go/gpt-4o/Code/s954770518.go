package main

import (
	"fmt"
	"sort"
)

func main() {
	// Declare a slice to hold 10 integers
	s := make([]int, 10)

	// Input 10 integers from the user
	for i := 0; i < 10; i++ {
		fmt.Scan(&s[i])
	}

	// Sort the slice of integers in ascending order
	sort.Ints(s)

	// Print the three largest integers from the sorted slice
	for i := 9; i > 6; i-- {
		fmt.Println(s[i])
	}
}

// <END-OF-CODE>
