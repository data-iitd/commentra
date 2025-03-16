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
	fmt.Scan(&n)

	// Read the elements and count their occurrences using Counter
	w := make(map[int]int)
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	for _, s := range strings.Split(scanner.Text(), " ") {
		i, _ := strconv.Atoi(s)
		w[i]++
	}

	// Initialize a counter for pairs that sum to zero
	c := 0

	// Iterate through each unique number in the counter
	for i := range w {
		// Check if the number is zero
		if i == 0 {
			// For zero, count pairs (w[i] choose 2) since both numbers are the same
			c += w[i] * (w[i] - 1)
		} else {
			// Check if the negative counterpart exists in the counter
			if _, ok := w[-i]; ok {
				// Count pairs formed by the number and its negative counterpart
				c += w[i] * w[-i]
			}
		}
	}

	// Since each pair is counted twice, divide the total count by 2 before printing
	fmt.Println(c / 2)
}

