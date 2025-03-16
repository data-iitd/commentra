
package main

import "fmt"

func task4(A, B, n int) int {
	// The function `task4` is designed to find the value of `X` such that `A * (X ** n) == B`.
	for X := -1000; X <= 1000; X++ {
		// It iterates over the range from -1000 to 1000 for `X`.
		if A*(X**n) == B {
			// For each value of `X`, it checks if the equation `A * (X ** n) == B` holds true.
			return X
			// If a solution is found, it returns the value of `X`.
		}
	}
	return -1
	// If no solution is found after the loop, it returns -1.
}

func main() {
	var A, B, n int
	fmt.Scan(&A, &B, &n)
	// The main part of the code takes input for `A`, `B`, and `n`.
	fmt.Println(task4(A, B, n))
	// Converts them to integers, and calls the `task4` function.
	// Finally, it prints the result returned by the `task4` function.
}

