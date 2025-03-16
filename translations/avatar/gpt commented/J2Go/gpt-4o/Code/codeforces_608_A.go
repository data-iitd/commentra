package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize a buffered reader for efficient input reading
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the number of pairs (n) and the minimum score (s)
	var n, s int
	fmt.Fscan(reader, &n, &s)

	// Initialize a variable to keep track of the maximum sum of pairs
	max := 0

	// Loop through each pair of integers
	for i := 0; i < n; i++ {
		var f, t int
		fmt.Fscan(reader, &f, &t)
		// Update max if the sum of f and t is greater than the current max
		if max < f+t {
			max = f + t
		}
	}

	// Print the maximum value between max and s
	if max < s {
		max = s
	}
	fmt.Fprintln(writer, max)
}

// <END-OF-CODE>
