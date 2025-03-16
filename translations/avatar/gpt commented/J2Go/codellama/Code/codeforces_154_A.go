package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a BufferedReader to read input from the standard input stream
	infile := bufio.NewReader(os.Stdin)

	// Read the first line of input and convert it to a character array
	arr, _ := infile.ReadString('\n')
	arr = arr[:len(arr)-1]

	// Get the length of the character array
	N := len(arr)

	// Initialize a HashSet to store unique strings (not used in this code)
	set := make(map[string]bool)

	// Read the number of queries K
	K, _ := strconv.Atoi(infile.Text())

	// Initialize the result counter
	res := 0

	// Loop through each query
	for k := 0; k < K; k++ {
		// Read the input string for the current query
		input, _ := infile.ReadString('\n')
		input = input[:len(input)-1]

		// Initialize counters for characters in the input string
		a := 0
		b := 0

		// Iterate through the character array
		for i := 0; i < N; i++ {
			// Count occurrences of the first character of the input string
			if arr[i] == input[0] {
				a++
			}
			// Count occurrences of the second character of the input string
			if arr[i] == input[1] {
				b++
			}
			// If neither character is found, update the result and reset counters
			if arr[i] != input[0] && arr[i] != input[1] {
				res += min(a, b)
				a = 0
				b = 0
			}
		}
		// Add the minimum count of the two characters to the result
		res += min(a, b)
	}

	// Output the final result
	fmt.Println(res)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// 