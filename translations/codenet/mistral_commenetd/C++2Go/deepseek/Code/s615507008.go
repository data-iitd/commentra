package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(N int, T []int, M int, P []int, X []int) {
	// Initialize a variable to store the answer for each query
	var ans int

	// Iterate through each query
	for i := 0; i < M; i++ {
		// Initialize the answer variable to zero
		ans = 0

		// Iterate through each element in T up to the position of the current query
		for j := 0; j < N; j++ {
			// If the current index j is equal to the position of the current query - 1
			if j == P[i]-1 {
				// Add the value of X[i] to the answer variable
				ans += X[i]
			} else {
				// Otherwise, add the value of the current element in T to the answer variable
				ans += T[j]
			}
		}

		// Print the answer for the current query
		fmt.Println(ans)
	}
}

func main() {
	// Initialize bufio objects
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the number of elements in T from the standard input
	scanner.Scan()
	N := 0
	fmt.Sscan(scanner.Text(), &N)

	// Initialize a slice T of size N
	T := make([]int, N)

	// Read the elements of T from the standard input
	for i := 0; i < N; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &T[i])
	}

	// Read the number of queries from the standard input
	scanner.Scan()
	M := 0
	fmt.Sscan(scanner.Text(), &M)

	// Initialize slices P and X of size M
	P := make([]int, M)
	X := make([]int, M)

	// Read the positions and values of the queries from the standard input
	for i := 0; i < M; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &P[i], &X[i])
	}

	// Call the solve function with the given arguments
	solve(N, T, M, P, X)
}

