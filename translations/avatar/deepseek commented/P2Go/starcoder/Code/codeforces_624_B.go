package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Step 1: Reading the number of elements (n)
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanln(reader, &n)

	// Step 2: Reading the list of elements (a)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &a[i])
	}

	// Step 3: Initializing variables
	pre := int(1e9)  // Initialize pre to infinity
	ans := 0         // Initialize ans to 0

	// Step 4: Sorting the list in descending order
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if a[i] < a[j] {
				a[i], a[j] = a[j], a[i]
			}
		}
	}

	// Step 5: Iterating through the list
	for j := 0; j < n; j++ {
		// Calculate the maximum value that can be added to ans
		ans += max(0, min(pre-1, a[j]))
		// Update pre to be the maximum of 0 and the minimum of pre - 1 and the current element
		pre = max(0, min(pre-1, a[j]))
	}

	// Step 6: Printing the result
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

