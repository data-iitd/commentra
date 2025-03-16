package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements
	var n int
	fmt.Fscan(reader, &n)

	// Create a map to count occurrences
	w := make(map[int]int)

	// Read the elements and count their occurrences
	for i := 0; i < n; i++ {
		var num int
		fmt.Fscan(reader, &num)
		w[num]++
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
			if _, exists := w[-i]; exists {
				// Count pairs formed by the number and its negative counterpart
				c += w[i] * w[-i]
			}
		}
	}

	// Since each pair is counted twice, divide the total count by 2 before printing
	fmt.Println(c / 2)
}

// <END-OF-CODE>
