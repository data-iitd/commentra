package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements
	var n int
	fmt.Fscan(reader, &n)

	// Read the input string and split it into a slice
	input, _ := reader.ReadString('\n')
	s := strings.Fields(strings.TrimSpace(input))

	// Count occurrences of each element
	counts := make(map[string]int)
	for _, item := range s {
		counts[item]++
	}

	// Reverse the slice to process elements in reverse order
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}

	// Initialize variables to track the index of the most frequent element and its value
	c, a := -1, ""

	// Iterate through each unique element in the count map
	for item, count := range counts {
		// Check if the current element's count is equal to the maximum count
		if count == maxCount(counts) {
			// If the index of the current element in the reversed slice is greater than the current index
			if index(s, item) > c {
				// Update the most frequent element and its index
				a = item
				c = index(s, item)
			}
		}
	}

	// Print the most frequent element that appears last in the original order
	fmt.Println(a)
}

// Function to find the maximum count in the map
func maxCount(counts map[string]int) int {
	max := 0
	for _, count := range counts {
		if count > max {
			max = count
		}
	}
	return max
}

// Function to find the index of an element in a slice
func index(s []string, item string) int {
	for i, v := range s {
		if v == item {
			return i
		}
	}
	return -1
}
