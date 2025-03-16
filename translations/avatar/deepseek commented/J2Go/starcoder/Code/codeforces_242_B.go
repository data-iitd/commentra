package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declaring variables to store the number of elements and the minimum and maximum values
	var n, left, right int

	// Reading the number of elements
	fmt.Scanf("%d\n", &n)

	// Initializing two slices to store the elements
	a := make([]int, n)
	b := make([]int, n)

	// Looping through n elements to read and update the slices and variables
	for i := 0; i < n; i++ {
		fmt.Scanf("%d\n", &a[i])
		fmt.Scanf("%d\n", &b[i])
		left = min(left, a[i])
		right = max(right, b[i])
	}

	// Looping through the slices to find the target element
	for i := 0; i < n; i++ {
		if left == a[i] && right == b[i] {
			fmt.Printf("%d\n", i+1) // Printing the 1-based index of the target element
			return
		}
	}

	// If no such element is found, print -1
	fmt.Printf("%d\n", -1)
}

// Defining a function to return the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Defining a function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

