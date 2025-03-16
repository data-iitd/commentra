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

	// Read the number of test cases
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Initialize id variable to 0
	id := 0

	// Read left and right boundary values for the first test case
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	l, _ := strconv.Atoi(parts[0])
	r, _ := strconv.Atoi(parts[1])

	// Iterate through the remaining test cases
	for i := 1; i < n; i++ {
		scanner.Scan()
		parts = strings.Split(scanner.Text(), " ")
		li, _ := strconv.Atoi(parts[0])
		ri, _ := strconv.Atoi(parts[1])

		// Check if the current test case overlaps with the previously defined boundary values
		if li <= l && r <= ri {
			// Update id variable to the index of the current test case
			id = i
		}

		// If the current test case does not overlap, keep id as n
		if li < l || r < ri {
			id = n
		}

		// Update boundary values based on the current test case
		if li < l {
			l = li
		}
		if ri > r {
			r = ri
		}
	}

	// Print the index of the test case that satisfies the condition, or -1 if no such test case exists
	if id == n {
		fmt.Println(-1)
	} else {
		fmt.Println(id + 1)
	}
}
