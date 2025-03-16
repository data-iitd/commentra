package main

import (
	"fmt"
	"strings"
)

func main() {
	// Ask user for the number of arrays (n) they want to input
	var n int
	fmt.Scan(&n)

	// Create a slice called 'q' to store these arrays
	q := make([][]string, 0, n)

	// Use a for loop to iterate through the range of 'n' and for each iteration,
	// ask the user for an array (a) and append it to our slice 'q'
	for i := 0; i < n; i++ {
		var input string
		fmt.Scan(&input)
		a := strings.Split(input, " ")
		q = append(q, a)
	}

	// Initialize count variable
	count := 0

	// Use another for loop to iterate through each array in our slice 'q'
	for _, j := range q {
		// For each array 'j', use another for loop to iterate through every other array in our slice 'q'
		for _, k := range q {
			// Exclude the current array 'j' from comparison
			if k == j {
				continue
			}
			// Check if the last element of the second array 'k' matches the first element of the first array 'j'
			if j[0] == k[len(k)-1] {
				// If it does, increment our 'count' variable
				count++
			}
		}
	}

	// Finally, print out the value of our 'count' variable
	fmt.Println(count)
}

// <END-OF-CODE>
