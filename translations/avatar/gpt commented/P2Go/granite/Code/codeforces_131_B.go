
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of elements
	n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())

	// Read the elements and count their occurrences using Counter
	w := make(map[int]int)
	for _, v := range bufio.NewReader(os.Stdin).Scan() {
		i, _ := strconv.Atoi(v)
		w[i]++
	}

	// Initialize a counter for pairs that sum to zero
	c := 0

	// Iterate through each unique number in the counter
	for i, v := range w {
		// Check if the number is zero
		if i == 0 {
			// For zero, count pairs (w[i] choose 2) since both numbers are the same
			c += v * (v - 1)
		} else {
			// Check if the negative counterpart exists in the counter
			if _, ok := w[-i]; ok {
				// Count pairs formed by the number and its negative counterpart
				c += v * w[-i]
			}
		}
	}

	// Since each pair is counted twice, divide the total count by 2 before printing
	fmt.Println(c / 2)
}
