package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin) // Creating a buffered reader for fast input
	writer := bufio.NewWriter(os.Stdout) // Creating a buffered writer for output

	var n, s int
	fmt.Fscan(reader, &n, &s) // Reading the first two integers n and s

	max := 0 // Initializing max to store the maximum sum of f and t

	for n > 0 { // Looping n times
		n-- // Decrementing n
		var f, t int
		fmt.Fscan(reader, &f, &t) // Reading the values f and t
		if max < f+t { // Checking if the sum of f and t is greater than the current max
			max = f + t // Updating max if the condition is true
		}
	}

	// Printing the maximum of max and s
	fmt.Fprintln(writer, maxInt(max, s))
	writer.Flush() // Flushing the writer to output the result
}

// Function to return the maximum of two integers
func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}
