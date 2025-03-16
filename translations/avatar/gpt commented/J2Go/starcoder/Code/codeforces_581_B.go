package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare a static TreeSet to hold long values (not used in this code)
	var set map[int64]bool

	// Read the number of elements
	n, _ := strconv.Atoi(readLine())

	// Initialize an array to hold the input values
	a := make([]int64, n)

	// Populate the array with input values
	for i := 0; i < n; i++ {
		a[i], _ = strconv.ParseInt(readLine(), 10, 64)
	}

	// Initialize a dp array to store the maximum values
	dp := make([]int64, n)

	// Fill the dp array with -1 to indicate uninitialized values
	for i := 0; i < n; i++ {
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
			fmt.Printf("%d ", 0)
		} else {
			// Otherwise, calculate and print the difference to the next maximum
			fmt.Printf("%d ", dp[i+1]-a[i]+1)
		}
	}

	// Print a new line after all outputs
	fmt.Println()
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	str, _, _ := buf.ReadLine()
	return strings.TrimRight(string(str), "\r\n")
}

// Debugging utility to print objects
func debug(obj...interface{}) {
	fmt.Println(obj...)
}

