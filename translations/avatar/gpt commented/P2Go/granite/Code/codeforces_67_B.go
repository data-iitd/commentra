
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input values for n and k
	u := bufio.NewScanner(os.Stdin)
	u.Scan()
	n, k := parseLine(u.Text())

	// Read the list of integers M from input
	u.Scan()
	M := parseLine(u.Text())

	// Initialize a variable m to zero (not used in the current logic)
	m := 0

	// Outer loop to iterate over each index j in the range of n
	for j := 0; j < n; j++ {
		// Inner loop to find the first index p where M[p] is zero
		for p := 0; p < n; p++ {
			if M[p] == 0 {
				// Print the index (1-based) where M[p] is zero
				fmt.Printf("%d ", p+1)
				break
			}
		}

		// Decrease the values in M from the start up to p + 1 - k
		for l := 0; l < p+1-k; l++ {
			M[l] -= 1
		}

		// Decrease the value at index p in M
		M[p] -= 1
	}
}

func parseLine(line string) []int {
	// Split the line into individual elements
	elements := strings.Split(line, " ")

	// Create an empty slice to store the parsed integers
	result := make([]int, len(elements))

	// Iterate over each element and convert it to an integer
	for i, element := range elements {
		value, _ := strconv.Atoi(element)
		result[i] = value
	}

	return result
}

