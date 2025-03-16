
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Define the number of elements 'n' and the difference 'd' in the input list
	var n, d int

	// Initialize an empty list 'x' to store the input elements
	var x []int

	// Initialize variables'm' and 'q' to 0
	var m, q int

	// Create a new scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of elements 'n' and the difference 'd' from the input
	fmt.Fscanf(scanner, "%d %d\n", &n, &d)

	// Read the 'n' elements from the input and convert them to integers
	x = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(scanner, "%d", &x[i])
	}

	// Iterate through the list 'x' to find the elements that are not in increasing order
	for i := 0; i < n-1; i++ {
		// Check if the current element is greater than or equal to the next element
		if x[i] >= x[i+1] {
			// Calculate the number of elements that need to be added to the next element
			q = int((x[i] - x[i+1]) / d + 1)
			// Add the calculated number of elements to the current and next elements
			m += q
			x[i+1] += q * d
		}
	}

	// Print the final result'm'
	fmt.Println(m)
}

