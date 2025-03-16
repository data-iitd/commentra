package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Create a new scanner to read from standard input
var stdin = bufio.NewScanner(os.Stdin)

func main() {
	// Read an array of integers from standard input
	arr := scanArrayInt()
	// Assign the first two elements of the array to variables a and b
	a, b := arr[0], arr[1]
	// Initialize the number of taps needed to 0
	tap := 0
	// Initialize the consent variable to 1 (the starting point)
	consent := 1
	
	// Loop until the consent value is less than b
	for consent < b {
		// Update consent by adding (a - 1) to it
		consent = consent + a - 1
		// Increment the tap count
		tap++
	}
	
	// Print the total number of taps needed
	fmt.Println(tap)
}

// Function to scan an array of integers from standard input
func scanArrayInt() []int {
	// Initialize an empty slice to hold the integers
	var ret = []int{}
	// Read a line from standard input
	stdin.Scan()
	// Split the input line into strings and convert each to an integer
	for _, s := range strings.Split(stdin.Text(), " ") {
		i, _ := strconv.Atoi(s) // Convert string to integer, ignoring errors
		ret = append(ret, i)    // Append the integer to the slice
	}
	// Return the slice of integers
	return ret
}
