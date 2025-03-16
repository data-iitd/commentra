
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a new scanner to read from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read an integer n from the standard input
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Create a slice a of size n to store the input integers
	a := make([]int, n)

	// Read n integers from the standard input and store them in the slice a
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}

	// Sort the slice a in descending order using the sort.Slice() function
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})

	// Initialize two variables, pre and ans, to float('inf') and 0, respectively
	pre := float('inf')
	ans := 0

	// Iterate through the slice a using a for loop
	for j := 0; j < n; j++ {
		// Calculate the maximum of 0 and the minimum of pre - 1 and a[j]. This value is added to ans.
		ans += max(0, min(pre-1, a[j]))

		// Update the value of pre to be the minimum of pre - 1 and a[j].
		pre = min(pre-1, a[j])
	}

	// After the loop, print the value of ans.
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

