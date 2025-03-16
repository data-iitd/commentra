package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Reading input from standard input
	reader := bufio.NewReader(os.Stdin)
	arr, _ := reader.ReadString('\n')
	arr = arr[:len(arr)-1] // Remove the newline character

	N := len(arr) // Store the length of the character array

	// Initialize a variable to store the final count
	res := 0

	// Read the number of test cases
	var K int
	fmt.Fscan(reader, &K)

	// Loop to process each test case
	for k := 0; k < K; k++ {
		var input string
		fmt.Fscan(reader, &input) // Read the input string for the current test case
		a, b := 0, 0              // Counters for the first and second characters of the input

		// Iterate over the characters of the input array
		for i := 0; i < N; i++ {
			if arr[i] == input[0] { // If the character matches the first character of the input
				a++
			} else if arr[i] == input[1] { // If the character matches the second character of the input
				b++
			} else { // If the character does not match either of the input characters
				res += min(a, b) // Add the minimum of a and b to the result
				a, b = 0, 0      // Reset the counters
			}
		}
		res += min(a, b) // Add the minimum of a and b to the result after the loop
	}

	// Print the final result
	fmt.Println(res)
}

// Helper function to return the minimum of two integers
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
