

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
	n, _ := strconv.Atoi(reader.ReadLine())

	// Initialize arrays to store the elements
	h := make([]int, n)
	g := make([]int, n)

	// Read n pairs of integers from the standard input
	for i := 0; i < n; i++ {
		h[i], _ = strconv.Atoi(reader.ReadLine())
		g[i], _ = strconv.Atoi(reader.ReadLine())
	}

	// Initialize the result variable to 0
	result := 0

	// Iterate through each element in array h
	for i := 0; i < n; i++ {
		// Compare each element in array h with each element in array g
		for j := 0; j < n; j++ {
			if h[i] == g[j] {
				// If a match is found, increment the result
				result++
			}
		}
	}

	// Print the value of result
	fmt.Println(result)
}

