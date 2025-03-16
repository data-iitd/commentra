package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Define the number of elements 'n' and the difference 'd' in the input list
	var n, d int
	fmt.Scan(&n, &d)

	// Initialize a slice 'x' to store the input elements
	x := make([]int, n)

	// Read the 'n' elements from the input and convert them to integers
	input := ""
	fmt.Scan(&input)
	elements := strings.Split(input, " ")
	for i := 0; i < n; i++ {
		x[i], _ = strconv.Atoi(elements[i])
	}

	// Initialize variables 'm' and 'q' to 0
	m := 0
	q := 0

	// Iterate through the slice 'x' to find the elements that are not in increasing order
	for i := 0; i < n-1; i++ {
		// Check if the current element is greater than or equal to the next element
		if x[i] >= x[i+1] {
			// Calculate the number of elements that need to be added to the next element
			q = (x[i] - x[i+1]) / d + 1
			// Add the calculated number of elements to the current and next elements
			m += q
			x[i+1] += q * d
		}
	}

	// Print the final result 'm'
	fmt.Println(m)
}

// <END-OF-CODE>
