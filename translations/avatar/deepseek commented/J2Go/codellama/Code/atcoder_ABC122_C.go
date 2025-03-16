
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input
	sc := bufio.NewScanner(os.Stdin)

	// Read the length of the string and the number of queries
	n, _ := strconv.Atoi(sc.Text())
	q, _ := strconv.Atoi(sc.Text())

	// Read the string as a character array
	c := sc.Text()

	// Read the ranges for the queries and store them in a 2D array
	range := make([][]int, q)
	for i := 0; i < q; i++ {
		range[i] = make([]int, 2)
		range[i][0], _ = strconv.Atoi(sc.Text())
		range[i][1], _ = strconv.Atoi(sc.Text())
	}

	// Initialize arrays to count "AC" fragments and store cumulative sums
	frag := make([]int, n+1)
	rui := make([]int, n+1)

	// Process the string to find "AC" fragments
	for i := 2; i <= n; i++ {
		if c[i-2] == 'A' && c[i-1] == 'C' {
			// Increment the count of "AC" fragments at position i
			frag[i]++
		}
		// Update the cumulative sum array
		rui[i] = rui[i-1] + frag[i]
	}

	// Process the queries
	for i := 0; i < q; i++ {
		left := range[i][0]
		right := range[i][1]
		// Calculate the number of "AC" fragments in the given range
		fmt.Println(rui[right] - rui[left])
	}
}

