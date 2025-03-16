package main

import (
	"fmt"
	"sort"
)

func main() {
	// Declare an integer to hold the number of elements
	var n int
	// Read the number of elements from user input
	fmt.Scan(&n)

	// Declare an integer to hold the number of largest elements to sum
	var a int
	// Read the number of largest elements to sum from user input
	fmt.Scan(&a)

	// Initialize a variable to hold the sum of the largest elements
	sum := 0

	// Declare a slice to hold the elements
	s := make([]int, n)

	// Read the elements into the slice from user input
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
	}

	// Sort the slice in non-decreasing order
	sort.Ints(s)

	// Sum the largest 'a' elements from the sorted slice
	for i := n - 1; i > n - a - 1; i-- {
		sum += s[i]
	}

	// Output the calculated sum of the largest 'a' elements
	fmt.Println(sum)
}

// <END-OF-CODE>
