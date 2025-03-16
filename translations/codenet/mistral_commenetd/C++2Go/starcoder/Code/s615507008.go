<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to solve the problem
func solve(N int, T []int, M int, P []int, X []int) {
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
			} else {
				// Otherwise, add the value of the current element in T to the answer variable
				ans += T[j]
			}
		}

		// Print the answer for the current query
		fmt.Println(ans)
	}
}

// Main function
func main() {
	// Read the number of elements in T from the standard input
	N, _ := strconv.Atoi(readLine())

	// Initialize a vector T of size N
	T := make([]int, N)

	// Read the elements of T from the standard input
	for i := 0; i < N; i++ {
		T[i], _ = strconv.Atoi(readLine())
	}

	// Read the number of queries from the standard input
	M, _ := strconv.Atoi(readLine())

	// Initialize vectors P and X of size M
	P := make([]int, M)
	X := make([]int, M)

	// Read the positions and values of the queries from the standard input
	for i := 0; i < M; i++ {
		line := readLine()
		P[i], X[i], _ = strconv.Atoi(line[:strings.Index(line, " ")])
	}

	// Call the solve function with the given arguments
	solve(N, T, M, P, X)
}

// Function to read a line from stdin
func readLine() string {
	// Declare a variable to store the input
	var input string

	// Read a line from stdin
	fmt.Scanln(&input)

	// Return the read line
	return input
}

Translate the above Go code to Python and end with comment "