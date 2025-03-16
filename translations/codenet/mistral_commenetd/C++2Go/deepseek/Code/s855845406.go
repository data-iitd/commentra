package main

import (
	"fmt"
)

func main() {
	// Declare and initialize two integer variables, N and A
	var N, A int
	fmt.Scan(&N) // Read the value of N from the standard input
	fmt.Scan(&A) // Read the value of A from the standard input

	// Calculate the result and print it to the standard output
	fmt.Println(N * N - A)
}

