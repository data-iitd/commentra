package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Use bufio for faster input reading
	scanner := bufio.NewScanner(os.Stdin)

	// Initialize a constant N for the size of the arrays
	const N = 368

	// Create two lists to track the values for 'M' and 'F'
	m := make([]int, N)  // List to track 'M' values
	f := make([]int, N)  // List to track 'F' values

	// Read the number of operations from input
	scanner.Scan()
	numOperations := scanner.Text()
	numOps, _ := strconv.Atoi(numOperations)

	for i := 0; i < numOps; i++ {
		// Read the operation type and the indices a and b
		scanner.Scan()
		line := scanner.Text()
		parts := strings.Split(line, " ")
		x := parts[0]
		a, _ := strconv.Atoi(parts[1])
		b, _ := strconv.Atoi(parts[2])

		// Update the corresponding list based on the operation type
		if x == "M" {
			m[a] += 2  // Increment the value at index a in the 'M' list
			m[b] -= 2  // Decrement the value at index b in the 'M' list
		} else {
			f[a] += 2  // Increment the value at index a in the 'F' list
			f[b] -= 2  // Decrement the value at index b in the 'F' list
		}
	}

	// Initialize variables to track cumulative sums and the minimum value
	a, b, c := 0, 0, 0

	// Iterate through the range of N to calculate cumulative sums and find the minimum
	for i := 0; i < N; i++ {
		a += m[i]  // Update cumulative sum for 'M'
		b += f[i]  // Update cumulative sum for 'F'

		// Update the minimum value if the current minimum of a and b is greater than c
		if min(a, b) > c {
			c = min(a, b)  // Set c to the new minimum value
		}
	}

	// Print the final minimum value found
	fmt.Println(c)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
