
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a scanner to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read the length of the array
	len, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Initialize an array of the specified length
	a := make([]int, len)

	// Populate the array with user input
	for i := 0; i < len; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}

	// Initialize variables to track the left and right indices of the mismatch
	l := 0
	r := 0

	// Flags to indicate the state of the search for mismatches
	flag := false
	isTrue := false

	// Loop through the array to find the first and second mismatches
	for i := 0; i < len; i++ {
		// Check if the current element does not match its expected value
		if a[i]!= i+1 &&!flag {
			// Set the left index to the current position (1-based index)
			l = i + 1
			// Set the flag to indicate the first mismatch has been found
			flag = true
			continue
		}
		// Check for the second mismatch
		if a[i]!= i+1 && flag {
			// Set the right index to the current position (1-based index)
			r = i + 1
			// Check if the previous element is less than the current element
			if a[r-1]-a[r-2] > 0 {
				// Set the isTrue flag to indicate a valid mismatch has been found
				isTrue = true
				break
			}
		}
	}

	// Output the result based on whether a valid mismatch was found
	fmt.Println(l, r)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

