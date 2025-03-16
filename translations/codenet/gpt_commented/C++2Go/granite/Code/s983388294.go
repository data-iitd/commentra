
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of elements
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(read(reader))

	// Initialize a slice to store the input elements
	a := make([]int, n)
	i := 0

	// Read n integers into the slice
	for i = 0; i < n; i++ {
		a[i], _ = strconv.Atoi(read(reader))
	}

	// Initialize a counter for the current expected number
	curr := 0

	// Iterate through the slice to find the longest prefix of consecutive integers starting from 1
	for i = 0; i < n; i++ {
		if a[i] == curr+1 {
			curr++ // Increment curr if the current element matches the expected value
		}
	}

	// Check if any consecutive integers were found
	if curr > 0 {
		// Print the number of elements not in the consecutive sequence
		fmt.Println(n - curr)
	} else {
		// If no consecutive integers were found, print -1
		fmt.Println(-1)
	}
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

