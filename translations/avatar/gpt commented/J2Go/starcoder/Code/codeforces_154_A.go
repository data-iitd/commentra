package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new buffered reader.
	reader := bufio.NewReader(os.Stdin)
	// Read the first line of input.
	input, _ := reader.ReadString('\n')
	// Convert the input to a character array.
	arr := []rune(input[:len(input)-1])
	// Get the length of the character array.
	N := len(arr)
	// Read the number of queries.
	K, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	// Initialize the result counter.
	res := 0
	// Loop through each query.
	for k := 0; k < K; k++ {
		// Read the input string for the current query.
		input, _ := reader.ReadString('\n')
		// Initialize counters for characters in the input string.
		a := 0
		b := 0
		// Iterate through the character array.
		for i := 0; i < N; i++ {
			// Count occurrences of the first character of the input string.
			if arr[i] == rune(input[0]) {
				a++
			}
			// Count occurrences of the second character of the input string.
			if arr[i] == rune(input[1]) {
				b++
			}
			// If neither character is found, update the result and reset counters.
			if arr[i]!= rune(input[0]) && arr[i]!= rune(input[1]) {
				res += min(a, b)
				a = b = 0
			}
		}
		// Add the minimum count of the two characters to the result.
		res += min(a, b)
	}
	// Output the final result.
	fmt.Println(res)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

