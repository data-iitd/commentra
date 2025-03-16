package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a BufferedReader to read input from the standard input stream
	reader := bufio.NewReader(os.Stdin)

	// Read the first line of input and convert it to a character slice
	arr, _ := reader.ReadString('\n')
	arr = arr[:len(arr)-1] // Remove the newline character

	// Get the length of the character slice
	N := len(arr)

	// Read the number of queries K
	var K int
	fmt.Fscan(reader, &K)

	// Initialize the result counter
	res := 0

	// Loop through each query
	for k := 0; k < K; k++ {
		// Read the input string for the current query
		var input string
		fmt.Fscan(reader, &input)

		// Initialize counters for characters in the input string
		a, b := 0, 0

		// Iterate through the character slice
		for i := 0; i < N; i++ {
			// Count occurrences of the first character of the input string
			if arr[i] == input[0] {
				a++
			} else if arr[i] == input[1] { // Count occurrences of the second character of the input string
				b++
			} else { // If neither character is found, update the result and reset counters
				res += min(a, b)
				a, b = 0, 0
			}
		}
		// Add the minimum count of the two characters to the result
		res += min(a, b)
	}

	// Output the final result
	fmt.Println(res)
}

// Helper function to return the minimum of two integers
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
