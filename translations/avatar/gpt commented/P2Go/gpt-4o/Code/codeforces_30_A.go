package main

import (
	"fmt"
	"strconv"
	"strings"
)

func task4(A, B, n int) interface{} {
	// Iterate through a range of possible values for X from -1000 to 1000
	for X := -1000; X <= 1000; X++ {
		// Check if the equation A * (X ** n) equals B
		if A*(power(X, n)) == B {
			// If a solution is found, return the value of X
			return X
		}
	}
	// If no solution is found in the range, return a message indicating no solution
	return "No solution"
}

// Helper function to calculate power
func power(base, exp int) int {
	result := 1
	for i := 0; i < exp; i++ {
		result *= base
	}
	return result
}

func main() {
	// Take input from the user and split it into three variables A, B, and n
	var input string
	fmt.Scanln(&input)
	parts := strings.Split(input, " ")

	A, _ := strconv.Atoi(parts[0])
	B, _ := strconv.Atoi(parts[1])
	n, _ := strconv.Atoi(parts[2])

	// Call the task4 function and print the result
	fmt.Println(task4(A, B, n))
}

// <END-OF-CODE>
