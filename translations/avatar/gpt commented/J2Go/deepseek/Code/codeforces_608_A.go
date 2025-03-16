package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize FastScanner for efficient input reading
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the number of pairs (n) and the minimum score (s)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	s, _ := strconv.Atoi(scanner.Text())

	// Initialize a variable to keep track of the maximum sum of pairs
	max := 0

	// Loop through each pair of integers
	for i := 0; i < n; i++ {
		// Read the two integers f and t
		scanner.Scan()
		f, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		t, _ := strconv.Atoi(scanner.Text())

		// Update max if the sum of f and t is greater than the current max
		if max < f+t {
			max = f + t
		}
	}

	// Print the maximum value between max and s
	fmt.Fprintln(writer, maxInt(max, s))
}

// Function to return the maximum of two integers
func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

