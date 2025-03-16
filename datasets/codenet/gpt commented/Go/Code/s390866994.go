package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// Function to print output to the console
func out(x ...interface{}) {
	fmt.Println(x...)
}

// Scanner for reading input from standard input
var sc = bufio.NewScanner(os.Stdin)

// Function to read an integer from input
func getInt() int {
	sc.Scan() // Read the next token
	i, e := strconv.Atoi(sc.Text()) // Convert the token to an integer
	if e != nil {
		panic(e) // Panic if there is an error in conversion
	}
	return i // Return the integer
}

// Function to read a string from input
func getString() string {
	sc.Scan() // Read the next token
	return sc.Text() // Return the string
}

// Basic utility functions for mathematical operations
func max(a, b int) int {
	if a > b {
		return a // Return a if it is greater than b
	}
	return b // Otherwise, return b
}

func min(a, b int) int {
	if a < b {
		return a // Return a if it is less than b
	}
	return b // Otherwise, return b
}

func asub(a, b int) int {
	if a > b {
		return a - b // Return the absolute difference if a is greater than b
	}
	return b - a // Otherwise, return the absolute difference
}

func abs(a int) int {
	if a >= 0 {
		return a // Return a if it is non-negative
	}
	return -a // Otherwise, return the negation of a
}

func main() {
	sc.Split(bufio.ScanWords) // Set the scanner to split input by words

	// Read the number of elements (N), maximum count (C), and time limit (K)
	N, C, K := getInt(), getInt(), getInt()
	t := make([]int, N) // Create a slice to hold the time values

	// Read N time values from input
	for i := 0; i < N; i++ {
		t[i] = getInt() // Store each time value in the slice
	}

	sort.Ints(t) // Sort the time values in ascending order

	// Initialize variables for counting groups and tracking the end time
	ans := 1 // Start with one group
	cnt := 1 // Count of elements in the current group
	end := t[0] + K // Calculate the end time for the first group

	// Iterate through the sorted time values
	for i := 1; i < N; i++ {
		// Check if we can add the current time to the current group
		if cnt < C && t[i] <= end {
			cnt++ // Increment the count of the current group
		} else {
			// Start a new group since the current time exceeds the end time
			cnt = 1 // Reset the count for the new group
			end = t[i] + K // Update the end time for the new group
			ans++ // Increment the group count
		}
	}
	out(ans) // Output the total number of groups formed
}
