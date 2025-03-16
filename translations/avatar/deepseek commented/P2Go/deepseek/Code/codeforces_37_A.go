package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements

	var l []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x) // Read the list of elements
		l = append(l, x)
	}

	// Initialize variables
	high := 1
	tower := n
	maximum := 1

	// Sort the list
	sort.Ints(l)

	// Loop through the sorted list
	for i := 1; i < n; i++ {
		if l[i] == l[i-1] { // Check if the current element is equal to the previous element
			tower-- // Decrement the tower count
			high++  // Increment the high count
		} else {
			if high > maximum { // Check if the current high is greater than the maximum
				maximum = high // Update the maximum
			}
			high = 1 // Reset high to 1
		}
	}

	if high > maximum { // Check if the final high is greater than the maximum
		maximum = high // Update the maximum
	}

	// Print the result
	fmt.Println(maximum, tower)
}

