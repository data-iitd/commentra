package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Step 4: Read input values
	scanner.Scan()
	n, _ := fmt.Sscan(scanner.Text(), &n)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &a[i])
	}

	// Step 5: Initialize a dynamic programming array
	dp := make([]int64, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = -1
	}

	// Step 6: Fill the dynamic programming array
	dp[n-1] = a[n-1]
	for i := n - 1; i >= 0; i-- {
		if dp[i+1] > a[i] {
			dp[i] = dp[i+1]
		} else {
			dp[i] = a[i]
		}
	}

	// Step 7: Calculate the result
	for i := 0; i < n; i++ {
		if a[i] > dp[i+1] {
			fmt.Fprint(writer, "0 ")
		} else {
			fmt.Fprintf(writer, "%d ", dp[i+1]-a[i]+1)
		}
	}

	// Step 8: Print the result
	fmt.Fprintln(writer)
}

