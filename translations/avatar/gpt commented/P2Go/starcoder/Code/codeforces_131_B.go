package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements
	var n int
	fmt.Scanf("%d\n", &n)

	// Read the elements and count their occurrences using a map
	w := make(map[int]int)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scanf("%d", &x)
		w[x]++
	}

	// Initialize a counter for pairs that sum to zero
	c := 0

	// Iterate through each unique number in the map
	for i := range w {
		// Check if the number is zero
		if i == 0 {
			// For zero, count pairs (w[i] choose 2) since both numbers are the same
			c += w[i] * (w[i] - 1)
		} else {
			// Check if the negative counterpart exists in the map
			if -i in w {
				// Count pairs formed by the number and its negative counterpart
				c += w[i] * w[-i]
			}
		}
	}

	// Since each pair is counted twice, divide the total count by 2 before printing
	fmt.Printf("%d\n", c/2)
}

