package main

import "fmt"

func main() {
	// Declare five integer variables to hold input values
	var a, b, c, d, e int

	// Read five integers from standard input
	fmt.Scan(&a, &b, &c, &d, &e)

	// Create a slice containing the input integers
	al := []int{a, b, c, d, e}

	// Iterate over the slice to find the first occurrence of zero
	for n, i := range al {
		// Check if the current element is zero
		if i == 0 {
			// Print the index (1-based) of the first zero found and exit the loop
			fmt.Println(n + 1)
			break
		}
	}
}
