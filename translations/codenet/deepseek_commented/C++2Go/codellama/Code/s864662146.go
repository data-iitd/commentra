package main

import (
	"fmt"
)

func main() {
	var N int // Declare an integer variable N and initialize it to 0
	fmt.Scan(&N) // Read an integer value from the standard input and store it in N
	A := make([]int, N) // Declare an array A of size N
	for i := 0; i < N; i++ { // Start a loop that iterates through the array A
		fmt.Scan(&A[i]) // Read N integers from the standard input and store them in the array A
	}

	m := A[0] // Initialize the variable m to the first element of the array A
	M := A[0] // Initialize the variable M to the first element of the array A
	for i := 0; i < N; i++ { // Start a loop that iterates through the array A
		if A[i] < m { // If the current element is less than m, update m to the current element
			m = A[i]
		}
		if A[i] > M { // If the current element is greater than M, update M to the current element
			M = A[i]
		}
	}

	fmt.Println(M - m) // Print the difference between the maximum and minimum values in the array A
}

