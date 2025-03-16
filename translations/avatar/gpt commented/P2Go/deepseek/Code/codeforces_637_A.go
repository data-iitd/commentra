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

	// Read the input string and split it into a list
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-2] // Remove the last character (newline)
	elements := strings.Split(s, " ")

	// Count the occurrences of each element in the list
	w := make(map[string]int)
	for _, element := range elements {
		w[element]++
	}

	// Reverse the list to process elements in reverse order
	for i, j := 0, len(elements)-1; i < j; i, j = i+1, j-1 {
		elements[i], elements[j] = elements[j], elements[i]
	}

	// Initialize variables to track the index of the most frequent element and its value
	c, a := -1, ""

	// Iterate through each unique element in the count dictionary
	for i := range w {
		// Check if the current element's count is equal to the maximum count
		if w[i] == maxValue(w) {
			// If the index of the current element in the reversed list is greater than the current index
			if indexOf(i, elements) > c {
				// Update the most frequent element and its index
				a = i
				c = indexOf(i, elements)
			}
		}
	}

	// Print the most frequent element that appears last in the original order
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

// Helper function to find the index of an element in a slice
func indexOf(element string, data []string) int {
	for k, v := range data {
		if v == element {
			return k
		}
	}
	return -1
}
