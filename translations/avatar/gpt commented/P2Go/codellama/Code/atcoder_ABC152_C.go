
package main

import "fmt"

func main() {
	// Taking input for the number of elements
	var N int
	fmt.Scan(&N)

	// Taking input for the elements and converting them into a list of integers
	n := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&n[i])
	}

	// Initializing a counter 'a' to count the number of elements that are less than the current element
	a := 1

	// Initializing 'pos' to keep track of the position of the last element that was smaller
	pos := 0

	// Looping through the array starting from the second element
	for i := 1; i < N; i++ {
		// Checking if the current element is smaller than the element at 'pos'
		if n[pos] > n[i] {
			a += 1 // Incrementing the counter if the condition is met
			pos = i // Updating 'pos' to the current index
		}
	}

	// Printing the final count of elements that were smaller than the previous ones
	fmt.Println(a)
}

