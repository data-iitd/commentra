package main

import "fmt"

func task4(A, B, n int) int {
	// Iterate through a range of possible values for X from -1000 to 1000
	for X := -1000; X <= 1000; X++ {
		// Check if the equation A * (X ** n) equals B
		if A*(X**n) == B {
			// If a solution is found, return the value of X
			return X
		}
	}
	// If no solution is found in the range, return a message indicating no solution
	return -1
}

func main() {
	// Take input from the user and split it into three variables A, B, and n
	var A, B, n int
	fmt.Scan(&A, &B, &n)

	// Call the task4 function with the converted integer values of A, B, and n, and print the result
	fmt.Println(task4(A, B, n))
}

