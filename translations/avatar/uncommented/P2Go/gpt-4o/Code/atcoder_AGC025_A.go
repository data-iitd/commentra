package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n string
	fmt.Scan(&n)

	a := []string{"10", "100", "1000", "10000", "100000"}
	newSum := 0

	// Convert the input string to a slice of integers
	for _, char := range n {
		num, err := strconv.Atoi(string(char))
		if err == nil {
			newSum += num
		}
	}

	// Check if n is in the predefined list
	if contains(a, n) {
		fmt.Println(10)
	} else {
		fmt.Println(newSum)
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
