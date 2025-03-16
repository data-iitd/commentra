package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare a variable to hold the size of the array
	var n int

	// Read the size of the array from user input
	fmt.Scanf("%d", &n)

	// Declare two arrays: one to hold the input values and another to count occurrences
	a := make([]int, n)
	count := make([]int, n)

	// Read the input values into the array 'a', starting from index 1
	for i := 1; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}

	// Initialize the count array to zero for all indices
	for i := 0; i < n; i++ {
		count[i] = 0
	}

	// Count the occurrences of each value in the array 'a'
	// The value at a[i] is used to index into the count array
	for i := 1; i < n; i++ {
		count[a[i]-1]++
	}

	// Print the counts of each index in the count array
	for i := 0; i < n; i++ {
		fmt.Printf("%d\n", count[i])
	}
}

