package main

import (
	"fmt"
	"os"
	"strconv"
)

func task4(A, B, n int) interface{} {
	// The function `task4` is designed to find the value of `X` such that `A * (X ** n) == B`.
	for X := -1000; X <= 1000; X++ {
		// It iterates over the range from -1000 to 1000 for `X`.
		if A*(X^n) == B {
			// For each value of `X`, it checks if the equation `A * (X ** n) == B` holds true.
			return X
			// If a solution is found, it returns the value of `X`.
		}
	}
	return "No solution"
	// If no solution is found after the loop, it returns "No solution".
}

func main() {
	var A, B, n int
	// The main part of the code takes input for `A`, `B`, and `n`.
	_, err := fmt.Scan(&A, &B, &n)
	if err != nil {
		fmt.Println("Error reading input:", err)
		os.Exit(1)
	}
	// Calls the `task4` function and prints the result.
	fmt.Println(task4(A, B, n))
}

// Note: In Go, the power operator is not `^` for exponentiation. 
// You may need to implement a function to calculate X^n if n is not small or if you want to handle negative bases correctly.
