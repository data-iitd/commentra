
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize a constant N for the size of the arrays
	N := 368

	// Create two lists to track the values for 'M' and 'F'
	m := make([]int, N) // List to track 'M' values
	f := make([]int, N) // List to track 'F' values

	// Read the number of operations from input
	for i := 0; i < int(readLine()); i++ {
		// Read the operation type and the indices a and b
		x, a, b := strings.Split(readLine(), " ")
		a, _ = strconv.Atoi(a) // Convert a to an integer
		b, _ = strconv.Atoi(b) // Convert b to an integer
		b++                    // Increment by 1 for range adjustment

		// Update the corresponding list based on the operation type
		if x == "M" {
			m[a] += 2 // Increment the value at index a in the 'M' list
			m[b] -= 2 // Decrement the value at index b in the 'M' list
		} else {
			f[a] += 2 // Increment the value at index a in the 'F' list
			f[b] -= 2 // Decrement the value at index b in the 'F' list
		}
	}

	// Initialize variables to track cumulative sums and the minimum value
	a, b, c := 0, 0, 0

	// Iterate through the range of N to calculate cumulative sums and find the minimum
	for i := 0; i < N; i++ {
		a += m[i] // Update cumulative sum for 'M'
		b += f[i] // Update cumulative sum for 'F'

		// Update the minimum value if the current minimum of a and b is greater than c
		if min(a, b) > c {
			c = min(a, b) // Set c to the new minimum value
		}
	}

	// Print the final minimum value found
	fmt.Println(c)
}

func readLine() string {
	str, _ := reader.ReadString('\n')
	for end := len(str) - 1; end >= 0; end-- {
		if str[end] != '\n' {
			break
		}
		str = str[:end]
	}
	return str
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

