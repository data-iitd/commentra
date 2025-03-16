
package main

import "fmt"

func main() {
	// Take the number of elements as input
	var N int
	fmt.Scan(&N)

	// Take a space-separated string of integers as input and convert them to a list of integers
	var n []int
	fmt.Scan(&n)

	// Convert the list to a NumPy array
	n = n

	// Initialize a counter to 1 and a position index to 0
	a := 1
	pos := 0

	// Loop through the array from the second element to the last
	for i := 1; i < N; i++ {
		// Check if the current minimum element is greater than the current element
		if n[pos] > n[i] {
			// Increment the counter and update the position index
			a += 1
			pos = i
		}
	}

	// Print the final count of elements that are greater than the current minimum
	fmt.Println(a)
}

