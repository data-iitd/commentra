
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner to read input from the standard input stream
	scanner := bufio.NewScanner(os.Stdin)

	// Read the first line of input and convert it to a character array
	scanner.Scan()
	arr := scanner.Text()

	// Get the length of the character array
	N := len(arr)

	// Initialize a map to store unique strings (not used in this code)
	set := make(map[string]bool)

	// Read the number of queries K
	scanner.Scan()
	K, _ := strconv.Atoi(scanner.Text())

	// Initialize the result counter
	res := 0

	// Loop through each query
	for k := 0; k < K; k++ {
		// Read the input string for the current query
		scanner.Scan()
		input := scanner.Text()

		// Initialize counters for characters in the input string
		a := 0
		b := 0

		// Iterate through the character array
		for i := 0; i < N; i++ {
			// Count occurrences of the first character of the input string
			if string(arr[i]) == string(input[0]) {
				a++
			}
			// Count occurrences of the second character of the input string
			else if string(arr[i]) == string(input[1]) {
				b++
			}
			// If neither character is found, update the result and reset counters
			else {
				res += int(math.Min(float64(a), float64(b)))
				a = 0
				b = 0
			}
		}
		// Add the minimum count of the two characters to the result
		res += int(math.Min(float64(a), float64(b)))
	}

	// Output the final result
	fmt.Println(res)
}

