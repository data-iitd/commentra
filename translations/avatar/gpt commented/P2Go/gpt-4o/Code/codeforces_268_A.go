package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read an integer input which represents the number of lists to be processed
	var n int
	fmt.Scan(&n)

	// Initialize a slice to store the input lists
	q := make([][]string, 0, n)

	// Initialize a counter to keep track of the matching conditions
	count := 0

	// Loop to read 'n' lines of input and store them in the slice 'q'
	for i := 0; i < n; i++ {
		var input string
		fmt.Scanln(&input)
		a := strings.Fields(input)
		q = append(q, a)
	}

	// Nested loop to compare each list in 'q' with every other list
	for _, j := range q {
		for _, k := range q {
			// Skip comparison if both lists are the same
			if &k == &j {
				continue
			}
			// Check if the first element of list 'j' matches the last element of list 'k'
			if j[0] == k[len(k)-1] {
				// Increment the count if the condition is met
				count++
			}
		}
	}

	// Print the final count of matching conditions
	fmt.Println(count)
}

// <END-OF-CODE>
