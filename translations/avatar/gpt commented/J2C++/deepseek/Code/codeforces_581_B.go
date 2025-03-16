package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a new Scanner for reading input
	scanner := bufio.NewScanner(os.Stdin)
	// Create a new PrintWriter for writing output
	printWriter := bufio.NewWriter(os.Stdout)
	
	// Read the number of elements
	scanner.Scan()
	n, _ := fmt.Sscan(scanner.Text(), &n)
	
	// Initialize an array to hold the input values
	a := make([]int64, n)
	
	// Populate the array with input values
	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &a[i])
	}
	
	// Initialize a dp array to store the maximum values
	dp := make([]int64, n+1)
	
	// Fill the dp array with -1 to indicate uninitialized values
	for i := 0; i < len(dp); i++ {
		dp[i] = -1
	}
	
	// Set the last element of dp to the last element of a
	dp[n-1] = a[n-1]
	
	// Fill the dp array with the maximum values from the end to the beginning
	for i := n - 1; i >= 0; i-- {
		if dp[i+1] > a[i] {
			dp[i] = dp[i+1]
		} else {
			dp[i] = a[i]
		}
	}
	
	// Iterate through the original array to calculate the output
	for i := 0; i < n; i++ {
		// If the current element is greater than the next maximum, print 0
		if a[i] > dp[i+1] {
			printWriter.WriteString("0 ")
		} else {
			// Otherwise, calculate and print the difference to the next maximum
			result := dp[i+1] - a[i] + 1
			printWriter.WriteString(fmt.Sprintf("%d ", result))
		}
	}
	
	// Print a new line after all outputs
	printWriter.WriteString("\n")
	
	// Flush the PrintWriter to ensure all data is written
	printWriter.Flush()
}
