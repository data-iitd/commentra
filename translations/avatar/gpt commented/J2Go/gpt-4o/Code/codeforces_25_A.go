package main

import (
	"fmt"
)

func main() {
	// Reading the number of elements in the array
	var n int
	fmt.Scan(&n)

	// Initializing a slice to store the input integers
	array := make([]int, n+1)

	// Loop to read n integers from the user and store them in the array
	for i := 1; i <= n; i++ {
		fmt.Scan(&array[i]) // Storing each integer in the array
	}

	// Initializing counters for odd and even numbers and their latest indices
	odd, even := 0, 0
	oddInd, evenInd := 0, 0

	// Loop to count odd and even numbers and track their latest indices
	for i := 1; i <= n; i++ {
		if array[i]%2 == 0 { // Checking if the number is even
			even++          // Incrementing the even counter
			evenInd = i     // Updating the index of the last even number
		} else { // The number is odd
			odd++          // Incrementing the odd counter
			oddInd = i     // Updating the index of the last odd number
		}
	}

	// Comparing the counts of odd and even numbers to determine which index to print
	if odd > even {
		fmt.Println(evenInd) // Print the index of the last even number if there are more odds
	} else {
		fmt.Println(oddInd) // Print the index of the last odd number otherwise
	}
}

// <END-OF-CODE>
