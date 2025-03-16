package main

import (
	"fmt"
	"strconv"
)

func task4(A int, B int, n int) string {
	// Iterate through a range of possible values for X from -1000 to 1000
	for X := -1000; X <= 1000; X++ {
		// Check if the equation A * (X ** n) equals B
		if A * (pow(X, n)) == B {
			// If a solution is found, return the value of X as a string
			return strconv.Itoa(X)
		}
	}
	// If no solution is found in the range, return a message indicating no solution
	return "No solution"
}

// Helper function to calculate X raised to the power of n
func pow(X int, n int) int {
	result := 1
	for i := 0; i < n; i++ {
		result *= X
	}
	return result
}

func main() {
	var A, B, n string
	fmt.Scan(&A, &B, &n)

	// Convert the input strings to integers
	AInt, _ := strconv.Atoi(A)
	BInt, _ := strconv.Atoi(B)
	nInt, _ := strconv.Atoi(n)

	// Call the task4 function with the converted integer values and print the result
	fmt.Println(task4(AInt, BInt, nInt))
}
