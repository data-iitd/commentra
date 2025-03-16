package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read an integer input for the number of elements
	var n int
	fmt.Scan(&n)

	// Read a list of integers from input
	lst := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&lst[i])
	}

	// Sort the list in ascending order
	sort.Ints(lst)

	// Reverse the list to get it in descending order
	for i, j := 0, len(lst)-1; i < j; i, j = i+1, j-1 {
		lst[i], lst[j] = lst[j], lst[i]
	}

	// Initialize a counter for odd numbers
	od := 0

	// Count the number of odd integers in the list
	for _, i := range lst {
		if i&1 == 1 { // Check if the number is odd using bitwise AND
			od++ // Increment the odd counter
		}
	}

	// Initialize variables for sum and a flag to track even number inclusion
	sum := 0
	ok := false

	// Iterate through the sorted list to calculate the desired sum
	for i := 0; i < n; i++ {
		if lst[i]%2 == 0 { // Check if the current number is even
			sum += lst[i] // Add even numbers directly to the sum
		} else {
			// If we have already included an odd number or there is more than one odd number left
			if ok || od > 1 {
				sum += lst[i] // Add the odd number to the sum
				od--          // Decrement the odd counter
				ok = !ok     // Toggle the flag to indicate an odd number has been included
			}
		}
	}

	// Print the final calculated sum
	fmt.Println(sum)
}

// <END-OF-CODE>
