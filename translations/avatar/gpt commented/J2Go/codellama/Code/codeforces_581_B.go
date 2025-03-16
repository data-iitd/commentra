package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a Scanner object for input and PrintWriter for output
	in := bufio.NewScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	// Read the number of elements
	in.Scan()
	n, _ := strconv.Atoi(in.Text())

	// Initialize an array to hold the input values
	a := make([]int64, n)

	// Populate the array with input values
	for i := 0; i < n; i++ {
		in.Scan()
		a[i], _ = strconv.ParseInt(in.Text(), 10, 64)
	}

	// Initialize a dp array to store the maximum values
	dp := make([]int64, n+1)

	// Fill the dp array with -1 to indicate uninitialized values
	for i := 0; i < n+1; i++ {
		dp[i] = -1
	}

	// Set the last element of dp to the last element of a
	dp[n-1] = a[n-1]

	// Fill the dp array with the maximum values from the end to the beginning
	for i := n - 1; i >= 0; i-- {
		dp[i] = max(dp[i+1], a[i])
	}

	// Iterate through the original array to calculate the output
	for i := 0; i < n; i++ {
		// If the current element is greater than the next maximum, print 0
		if a[i] > dp[i+1] {
			fmt.Fprintf(out, "0 ")
		} else {
			// Otherwise, calculate and print the difference to the next maximum
			fmt.Fprintf(out, "%d ", dp[i+1]-a[i]+1)
		}
	}

	// Print a new line after all outputs
	fmt.Fprintln(out)

	// Close the PrintWriter
	out.Flush()
}

// Debugging utility to print objects
func debug(a ...interface{}) {
	fmt.Fprintln(os.Stderr, a...)
}

// max returns the maximum of two integers
func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// 