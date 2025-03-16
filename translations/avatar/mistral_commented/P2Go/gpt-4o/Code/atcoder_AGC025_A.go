package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Take an input from the user and assign it to the variable 'n'
	var n string
	fmt.Scanln(&n)

	// Initialize a slice 'a' with some strings representing numbers
	a := []string{"10", "100", "1000", "10000", "100000"}

	// Convert each character of the input 'n' to an integer and sum them up
	newSum := 0
	for _, char := range n {
		num, err := strconv.Atoi(string(char))
		if err == nil {
			newSum += num
		}
	}

	// Check if the input 'n' is present in the slice 'a'
	if contains(a, n) {
		// If the input 'n' is present in the slice 'a', then print the number 10
		fmt.Println(10)
	} else {
		// If the input 'n' is not present in the slice 'a', then print the value of the variable 'newSum'
		fmt.Println(newSum)
	}
}

// Helper function to check if a string is present in a slice
func contains(slice []string, item string) bool {
	for _, v := range slice {
		if v == item {
			return true
		}
	}
	return false
}
