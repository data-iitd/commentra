package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a new scanner to read from standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of strings to be processed
	scanner.Scan()
	n := scanner.Text()

	// Read the strings and split the last string by space
	scanner.Scan()
	s := scanner.Text()
	words := strings.Split(s, " ")

	// Create a map to store the occurrences of each string
	w := make(map[string]int)

	// Iterate through each string and count occurrences
	for _, word := range words[:len(words)-1] {
		w[word]++
	}

	// Initialize variables for storing the index of the longest string and its value
	c, a := -1, ""

	// Iterate through each string in the map
	for i := range w {
		// If the current string has the maximum occurrences
		if w[i] == maxValue(w) {
			// If its index in the original list is greater than the current index of the longest string
			if indexOf(i, words[:len(words)-1]) > c {
				// Update the longest string and its index
				a = i
				c = indexOf(i, words[:len(words)-1])
			}
		}
	}

	// Print the longest string
	fmt.Println(a)
}

// Helper function to find the maximum value in a map
func maxValue(m map[string]int) int {
	max := 0
	for _, value := range m {
		if value > max {
			max = value
		}
	}
	return max
}

// Helper function to find the index of a string in a slice
func indexOf(element string, data []string) int {
	for k, v := range data {
		if v == element {
			return k
		}
	}
	return -1
}
