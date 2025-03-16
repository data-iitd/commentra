
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize variables for storing the number of strings, the strings, and the occurrences of each string
	var n int
	var s []string
	var w map[string]int

	// Create a new scanner to read input from standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of strings to be processed
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())

	// Read the strings and split the last string by space
	scanner.Scan()
	s = strings.Split(scanner.Text(), " ")[:n-1]

	// Create a map to store the occurrences of each string
	w = make(map[string]int)

	// Iterate through each string in the input
	for _, v := range s {
		// Increment the count of the current string in the map
		w[v]++
	}

	// Initialize variables for storing the index of the longest string and its value
	var c, a int

	// Iterate through each string in the map
	for i, v := range w {
		// If the current string has the maximum occurrences
		if v == max(w) {
			// If its index in the original list is greater than the current index of the longest string
			if i > c {
				// Update the longest string and its index
				a = i
				c = i
			}
		}
	}

	// Print the longest string
	fmt.Println(s[a])
}

func max(m map[string]int) int {
	// Initialize variables for storing the maximum value and its corresponding key
	var maxVal int
	var maxKey string

	// Iterate through each key-value pair in the map
	for k, v := range m {
		// If the current value is greater than the maximum value
		if v > maxVal {
			// Update the maximum value and its corresponding key
			maxVal = v
			maxKey = k
		}
	}

	// Return the maximum value
	return maxVal
}

