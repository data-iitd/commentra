package main

import (
	"fmt"
	"strings"
)

func main() {
	var t, h []string
	var n int
	var taro, hanako int
	var i int

	// Read the number of strings to be compared from the standard input
	fmt.Scan(&n)

	// Allocate memory for t and h arrays
	t = make([]string, n)
	h = make([]string, n)

	// Initialize the loops for t and h arrays
	for i = 0; i < n; i++ {
		// Read strings from the standard input and store them in t and h arrays
		fmt.Scan(&t[i])
		fmt.Scan(&h[i])

		// Compare the strings and update the scores accordingly
		if strings.Compare(t[i], h[i]) < 0 {
			hanako += 3
		} else if strings.Compare(t[i], h[i]) > 0 {
			taro += 3
		} else {
			taro += 1
			hanako += 1
		}
	}

	// Print the scores for Taro and Hanako
	fmt.Printf("%d %d\n", taro, hanako)

	// No need to free memory in Go as it is handled by the garbage collector
}

