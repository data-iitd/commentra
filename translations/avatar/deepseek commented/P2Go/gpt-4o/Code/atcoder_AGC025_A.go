package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n string
	fmt.Scan(&n) // Taking an input from the user and storing it in the variable `n`.

	a := []string{"10", "100", "1000", "10000", "100000"} // Defining a slice `a` containing string representations of numbers.

	newSum := 0
	for _, digit := range n { // Converting the input `n` to a list of its digits and summing them up.
		d, _ := strconv.Atoi(string(digit)) // Convert each character to an integer.
		newSum += d
	}

	if contains(a, n) { // Checking if the input `n` is in the slice `a`.
		fmt.Println(10) // If `n` is in `a`, print the number 10.
	} else { // Otherwise...
		fmt.Println(newSum) // Print the value of `newSum`.
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
