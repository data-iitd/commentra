package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of pairs
	var n int
	fmt.Scanf("%d", &n)

	// Initialize two slices to store the pairs
	a := make([]int, n)
	b := make([]int, n)

	// Initialize left to infinity and right to zero
	left := int(^uint(0) >> 1)
	right := 0

	// Read the pairs and determine the minimum and maximum values
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
		fmt.Scanf("%d", &b[i])

		// Update left to the minimum value found in a
		if left > a[i] {
			left = a[i]
		}

		// Update right to the maximum value found in b
		if right < b[i] {
			right = b[i]
		}
	}

	// Check for a pair that matches the left and right bounds
	for i := 0; i < n; i++ {
		// If the current pair matches the min and max values
		if left == a[i] && right == b[i] {
			// Print the index (1-based) and exit
			fmt.Println(i + 1)
			return
		}
	}

	// If no matching pair is found, print -1
	fmt.Println(-1)
}

