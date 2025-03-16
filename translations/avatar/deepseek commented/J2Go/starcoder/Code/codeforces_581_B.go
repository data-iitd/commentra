package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Step 4: Read input values
	var n int
	fmt.Fscan(reader, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &a[i])
	}

	// Step 5: Initialize a dynamic programming array
	dp := make([]int, n+1)
	for i := 0; i < n+1; i++ {
		dp[i] = -1
	}

	// Step 6: Fill the dynamic programming array
	dp[n-1] = a[n-1]
	for i := n - 1; i >= 0; i-- {
		dp[i] = max(dp[i+1], a[i])
	}

	// Step 7: Calculate the result
	for i := 0; i < n; i++ {
		if a[i] > dp[i+1] {
			fmt.Fprint(writer, 0, " ")
		} else {
			fmt.Fprint(writer, dp[i+1]-a[i]+1, " ")
		}
	}

	// Step 8: Print the result
	fmt.Fprintln(writer)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Step 9: Debugging (optional)
func debug(obj...interface{}) {
	fmt.Fprintln(os.Stderr, obj...)
}

