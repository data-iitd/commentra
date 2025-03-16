
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner to read input from the user
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements (n) and the threshold value (m)
	n, _ := strconv.Atoi(read(reader))
	m, _ := strconv.Atoi(read(reader))

	// Initialize two slices: one for the values and one for their original indices
	values := make([]int, n)
	indices := make([]int, n)

	// Populate the slices with input values and their corresponding indices
	for i := 0; i < n; i++ {
		values[i], _ = strconv.Atoi(read(reader))
		indices[i] = i + 1
	}

	// Variable to store the final answer (the index of the last processed element)
	var ans int

	// Process the elements in the slices until they are empty
	for len(values) > 0 {
		// Check if the front element of values is less than or equal to m
		if values[0] <= m {
			// If yes, remove it from values and update the answer with the corresponding index from indices
			ans = indices[0]
			values = values[1:]
			indices = indices[1:]
		} else if values[0] > m {
			// If the front element is greater than m
			// Remove the element, reduce it by m, and add it back to values
			values[0] -= m
			// Remove the index from indices and add it back to maintain the order
			indices[0] = indices[len(indices)-1]
			indices = indices[:len(indices)-1]
		}
	}

	// Output the final answer
	fmt.Println(ans)
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

