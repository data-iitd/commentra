package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of test cases
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(reader))

	// Read the array of integers
	input, _ := reader.ReadString('\n')
	a := parseIntArray(input)

	// Initialize variables
	currentLevel := 0
	counter := 0
	counterTurns := -1

	// Main loop
	for counter < len(a) {
		// Increment turns counter
		counterTurns++

		// Iterate through the array
		for i := 0; i < len(a); i++ {
			// If current index is valid and its value is less than or equal to current level
			if a[i] != -1 && a[i] <= currentLevel {
				// Increment counter and mark the index as visited
				counter++
				a[i] = -1
			}
		}

		// Reverse the array
		for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
			a[i], a[j] = a[j], a[i]
		}
	}

	// Print the result
	fmt.Println(counterTurns)
}

func readLine(reader *bufio.Reader) string {
	input, _ := reader.ReadString('\n')
	return strings.TrimSpace(input)
}

func parseIntArray(input string) []int {
	parts := strings.Fields(input)
	intArray := make([]int, len(parts))
	for i, part := range parts {
		intArray[i], _ = strconv.Atoi(part)
	}
	return intArray
}
