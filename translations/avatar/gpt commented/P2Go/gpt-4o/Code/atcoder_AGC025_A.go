package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read input from the user
	var n string
	fmt.Scanln(&n)

	// Define a slice of string representations of powers of ten
	a := []string{"10", "100", "1000", "10000", "100000"}

	// Convert the input string into a slice of integers and calculate the sum
	sum := 0
	for _, char := range n {
		num, _ := strconv.Atoi(string(char))
		sum += num
	}

	// Check if the input is one of the predefined values in the slice 'a'
	if contains(a, n) {
		// If the input matches one of the predefined values, print 10
		fmt.Println(10)
	} else {
		// If the input does not match, print the calculated sum
		fmt.Println(sum)
	}
}

// Helper function to check if a string is in a slice
func contains(slice []string, item string) bool {
	for _, s := range slice {
		if s == item {
			return true
		}
	}
	return false
}

// <END-OF-CODE>
