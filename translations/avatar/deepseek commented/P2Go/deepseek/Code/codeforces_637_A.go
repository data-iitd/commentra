package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the integer n and the list of strings s from standard input
	var n int
	fmt.Fscan(reader, &n)
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)
	s = strings.Split(s, " ")

	// Create a map w from the list s
	w := make(map[string]int)
	for _, item := range s {
		w[item]++
	}

	// Reverse the list s
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}

	// Initialize two variables c and a to -1 and 0 respectively
	c, a := -1, ""

	// Iterate over the items in the map w
	for item := range w {
		// Check if the count of the item is equal to the maximum count in the map
		if w[item] == maxValue(w) {
			// Check if the index of the item in the reversed list s is greater than the current value of c
			if indexOf(item, s) > c {
				// Update the value of a to the current item and update the value of c to the index of the current item in the reversed list s
				a = item
				c = indexOf(item, s)
			}
		}
	}

	// Print the value of a
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

// Helper function to find the index of an item in a slice
func indexOf(item string, slice []string) int {
	for i, s := range slice {
		if s == item {
			return i
		}
	}
	return -1
}

