package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of intervals
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Initialize the index for the result
	id := 0

	// Read the first interval's bounds
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	l, _ := strconv.Atoi(parts[0])
	r, _ := strconv.Atoi(parts[1])

	// Iterate through the remaining intervals
	for i := 1; i < n; i++ {
		scanner.Scan()
		parts = strings.Split(scanner.Text(), " ")
		li, _ := strconv.Atoi(parts[0])
		ri, _ := strconv.Atoi(parts[1])

		// Check if the current interval completely contains the previous one
		if li <= l && r <= ri {
			id = i // Update the index to the current interval
		} else if li < l || r < ri {
			id = n // Mark as overlapping by setting id to n
		}

		// Update the bounds of the union of intervals
		if li < l {
			l = li
		}
		if ri > r {
			r = ri
		}
	}

	// Print the result: -1 if no valid interval found, otherwise print the 1-based index of the interval
	if id == n {
		fmt.Println(-1)
	} else {
		fmt.Println(id + 1)
	}
}
