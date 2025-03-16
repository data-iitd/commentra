package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a buffered reader to read from standard input
	reader := bufio.NewReader(os.Stdin)

	// Read the number of strings to be processed
	var n int
	fmt.Fscan(reader, &n)

	// Read the strings and split the last string by space
	input, _ := reader.ReadString('\n')
	s := strings.Fields(input)

	// Create a map to store the occurrences of each string
	w := make(map[string]int)
	for _, str := range s {
		w[str]++
	}

	// Initialize variables for storing the index of the longest string and its value
	c, a := -1, ""

	// Iterate through each string in the map
	for str, count := range w {
		// If the current string has the maximum occurrences
		if count == maxCount(w) {
			// If its index in the original list is greater than the current index of the longest string
			if indexOf(s, str) > c {
				// Update the longest string and its index
				a = str
				c = indexOf(s, str)
			}
		}
	}

	// Print the longest string
	fmt.Println(a)
}

// Function to find the maximum count in the map
func maxCount(w map[string]int) int {
	max := 0
	for _, count := range w {
		if count > max {
			max = count
		}
	}
	return max
}

// Function to find the index of a string in a slice
func indexOf(s []string, str string) int {
	for i, v := range s {
		if v == str {
			return i
		}
	}
	return -1
}
