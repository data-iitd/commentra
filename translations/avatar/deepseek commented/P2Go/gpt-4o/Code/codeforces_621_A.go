package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements in the list

	lst := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&lst[i]) // Read the list of integers
	}

	sort.Sort(sort.Reverse(sort.IntSlice(lst))) // Sort the list in descending order

	// Initialize a counter for odd numbers
	od := 0
	for _, i := range lst {
		if i%2 != 0 { // Check if the number is odd
			od++
		}
	}

	// Initialize sum to accumulate the result
	sum := 0
	ok := false // Initialize a flag to track if an odd number has been added

	// Iterate through the list to process each number
	for i := 0; i < n; i++ {
		if lst[i]%2 == 0 { // Check if the number is even
			sum += lst[i] // Add even numbers to sum
		} else {
			if ok || od > 1 { // Check if an odd number can be added
				sum += lst[i] // Add odd number to sum
				od--          // Decrement the count of odd numbers
				ok = !ok     // Toggle the flag
			}
		}
	}

	fmt.Println(sum) // Print the final sum
}

// <END-OF-CODE>
