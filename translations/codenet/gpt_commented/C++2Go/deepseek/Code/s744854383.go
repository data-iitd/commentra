package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of elements
	var N int
	fmt.Scan(&N)

	// Initialize a slice to store the elements
	a := make([]int, N)
	// Read the elements into the slice
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	for i := 0; i < N; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}

	// Initialize index and answer counter
	idx := 1
	ans := 0

	// Iterate through the slice to count mismatches
	for i := 0; i < N; i++ {
		// If the current element matches the expected index
		if a[i] == idx {
			// Move to the next expected index
			idx++
		} else {
			// Count the mismatch
			ans++
		}
	}

	// If no elements matched the expected index
	if idx == 1 {
		fmt.Println(-1) // Output -1 to indicate no matches
	} else {
		// Output the count of mismatches
		fmt.Println(ans)
	}
}

