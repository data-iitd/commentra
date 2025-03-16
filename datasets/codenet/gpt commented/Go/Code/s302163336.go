package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Initialize a scanner to read input from standard input
var sc = bufio.NewScanner(os.Stdin)

func main() {
	// Set the scanner to split input by whitespace
	sc.Split(bufio.ScanWords)

	// Read the number of elements (n) and the number of comparisons (m)
	n := nextInt()
	m := nextInt()

	// Create a slice to hold the heights and a slice to track which elements are "good"
	h := make([]int, n)
	good := make([]bool, n)

	// Read the heights and initialize the good slice to true
	for i := 0; i < n; i++ {
		h[i] = nextInt() // Read height for each element
		good[i] = true   // Initially, all elements are considered "good"
	}

	// Process each comparison
	for i := 0; i < m; i++ {
		ai := nextInt() - 1 // Read the first index (0-based)
		bi := nextInt() - 1 // Read the second index (0-based)

		// Compare the heights and update the good slice accordingly
		if h[ai] > h[bi] {
			good[bi] = false // If ai is taller, bi is not "good"
		} else if h[ai] < h[bi] {
			good[ai] = false // If bi is taller, ai is not "good"
		} else {
			// If heights are equal, mark both as not "good"
			good[ai] = false
			good[bi] = false
		}
	}

	// Count the number of "good" elements
	ans := 0
	for i := 0; i < n; i++ {
		if good[i] {
			ans++ // Increment count for each "good" element
		}
	}

	// Print the result: the number of "good" elements
	fmt.Println(ans)
}

// nextInt reads the next integer from the input
func nextInt() int {
	sc.Scan() // Scan the next token
	i, e := strconv.Atoi(sc.Text()) // Convert the scanned text to an integer
	if e != nil {
		panic(e) // Panic if there is an error in conversion
	}
	return i // Return the integer value
}
