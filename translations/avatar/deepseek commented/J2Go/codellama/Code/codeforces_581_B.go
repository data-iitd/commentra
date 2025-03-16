package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Step 1: Initialize a scanner
	scanner := bufio.NewScanner(os.Stdin)

	// Step 2: Read input values
	var n int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	a := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}

	// Step 3: Initialize a dynamic programming array
	dp := make([]int, n+1)
	for i := 0; i < n+1; i++ {
		dp[i] = -1
	}

	// Step 4: Fill the dynamic programming array
	dp[n-1] = a[n-1]
	for i := n - 1; i >= 0; i-- {
		dp[i] = max(dp[i+1], a[i])
	}

	// Step 5: Calculate the result
	for i := 0; i < n; i++ {
		if a[i] > dp[i+1] {
			fmt.Printf("%d ", 0)
		} else {
			fmt.Printf("%d ", dp[i+1]-a[i]+1)
		}
	}

	// Step 6: Print the result
	fmt.Println()

	// Step 7: Debugging (optional)
	// debug(dp)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Step 8: Debugging (optional)
func debug(obj ...interface{}) {
	fmt.Println(obj)
}

// END-OF-CODE
