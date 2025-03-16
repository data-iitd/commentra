package main

import (
	"fmt"
	"strconv"
	"strings"
)

// Function to find a number X raised to the power n such that A * X^n equals B
func task4(A, B, n int) interface{} {
	// Iterate through all possible values of X from -1000 to 1000
	for X := -1000; X <= 1000; X++ {
		// Check if the condition A * X^n equals B is satisfied
		if A*(pow(X, n)) == B {
			// If the condition is satisfied, return the value of X
			return X
		}
	}
	// If no solution is found, return a message indicating that
	return "No solution"
}

// Function to calculate X raised to the power n
func pow(x, n int) int {
	result := 1
	for i := 0; i < n; i++ {
		result *= x
	}
	return result
}

func main() {
	// Get input values of A, B, and n from the user
	var input string
	fmt.Scanln(&input)

	// Split the input string and convert to integers
	parts := strings.Split(input, " ")
	A, _ := strconv.Atoi(parts[0])
	B, _ := strconv.Atoi(parts[1])
	n, _ := strconv.Atoi(parts[2])

	// Call the function and print the result
	fmt.Println(task4(A, B, n))
}

// <END-OF-CODE>
