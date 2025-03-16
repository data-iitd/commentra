
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to solve the problem
func solve(N int, // Number of elements in T
	T []int, // Input vector T
	M int, // Number of queries
	P []int, // Position of each query
	X []int // Value of each query
) {
	// Initialize a variable to store the answer for each query
	ans := 0

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
			}
			// Otherwise, add the value of the current element in T to the answer variable
			else {
				ans += T[j]
			}
		}

		// Print the answer for the current query
		fmt.Println(ans)
	}
}

// Main function
func main() {
	// Initialize iostream objects
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	// Read the number of elements in T from the standard input
	N, _ := strconv.Atoi(reader.ReadLine()[2:])

	// Initialize a vector T of size N
	T := make([]int, N)

	// Read the elements of T from the standard input
	for i := 0; i < N; i++ {
		T[i], _ = strconv.Atoi(reader.ReadLine()[2:])
	}

	// Read the number of queries from the standard input
	M, _ := strconv.Atoi(reader.ReadLine()[2:])

	// Initialize vectors P and X of size M
	P := make([]int, M)
	X := make([]int, M)

	// Read the positions and values of the queries from the standard input
	for i := 0; i < M; i++ {
		line := reader.ReadLine()[2:]
		P[i], _ = strconv.Atoi(line[:len(line)-2])
		X[i], _ = strconv.Atoi(line[len(line)-2:])
	}

	// Call the solve function with the given arguments
	solve(N, T, M, P, X)

	// Flush the writer to ensure all output is written to the standard output
	writer.Flush()
}

