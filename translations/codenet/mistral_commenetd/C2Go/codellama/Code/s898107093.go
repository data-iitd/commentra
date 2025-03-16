
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables
	var t, h []string // t and h are arrays of strings
	var n int // number of strings to be compared
	var taro, hanako int // score for Taro and Hanako
	var i int // loop counter

	// Read the number of strings to be compared from the standard input
	n, _ = strconv.Atoi(os.Args[1])

	// Initialize the loops for t and h arrays
	for i = 0; i < n; i++ {
		// Read strings from the standard input and store them in t and h arrays
		t = append(t, os.Args[2*i+2])
		h = append(h, os.Args[2*i+3])

		// Compare the strings and update the scores accordingly
		if strings.Compare(t[i], h[i]) < 0 {
			hanako += 3 // Hanako gets 3 points if the current string in t is smaller than the corresponding string in h
		} else if strings.Compare(t[i], h[i]) > 0 {
			taro += 3 // Taro gets 3 points if the current string in t is larger than the corresponding string in h
		} else { // If the strings are equal
			taro += 1 // Taro gets 1 point if the strings are equal
			hanako += 1 // Hanako gets 1 point if the strings are equal
		}
	}

	// Print the scores for Taro and Hanako
	fmt.Printf("%d %d\n", taro, hanako)

	// Return 0 to indicate successful execution of the program
	os.Exit(0)
}

