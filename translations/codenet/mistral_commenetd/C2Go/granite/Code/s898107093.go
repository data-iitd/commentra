

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables
	var (
		n        int
		taro     int
		hanako   int
		t        []string
		h        []string
		i        int
		s        string
		err      error
		reader   *bufio.Reader
		scanner  *bufio.Scanner
		strSlice []string
	)

	// Initialize the reader
	reader = bufio.NewReader(os.Stdin)

	// Read the number of strings to be compared from the standard input
	fmt.Fscanf(reader, "%d\n", &n)

	// Initialize the t and h arrays
	t = make([]string, n)
	h = make([]string, n)

	// Initialize the loop for t and h arrays
	for i = 0; i < n; i++ {
		// Read strings from the standard input and store them in t and h arrays
		fmt.Fscanf(reader, "%s\n", &s)
		t[i] = s
		fmt.Fscanf(reader, "%s\n", &s)
		h[i] = s

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
}

