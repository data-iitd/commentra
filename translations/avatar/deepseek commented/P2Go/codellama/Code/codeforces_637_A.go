package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read the integer n and the list of strings s from standard input
	var n int
	fmt.Scan(&n)
	s := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
	}

	// Create a Counter object w from the list s
	w := make(map[string]int)
	for _, v := range s {
		w[v]++
	}

	// Reverse the list s
	s = reverse(s)

	// Initialize two variables c and a to -1 and 0 respectively
	c, a := -1, 0

	// Iterate over the items in the Counter object w
	for i, v := range w {
		// Check if the count of the item is equal to the maximum count in the Counter object
		if v == max(w) {
			// Check if the index of the item in the reversed list s is greater than the current value of c
			if s.Index(i) > c {
				// Update the value of a to the current item and update the value of c to the index of the current item in the reversed list s
				a = i
				c = s.Index(i)
			}
		}
	}

	// Print the value of a
	fmt.Println(a)
}

func reverse(s []string) []string {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
	return s
}

func max(m map[string]int) int {
	max := 0
	for _, v := range m {
		if v > max {
			max = v
		}
	}
	return max
}

// 