package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Solve the problem
func solve(N int, M int, Q int, a []int, b []int, c []int, d []int) {
	// Initialize the result variable to store the maximum score
	res := 0

	// Recursive function to explore combinations of numbers
	func rec(A []int) {
		// Base case: if the length of A equals N, calculate the score
		if len(A) == N {
			ans := 0
			// Check each query to see if it contributes to the score
			for i := 0; i < Q; i++ {
				if A[b[i]-1]-A[a[i]-1] == c[i] {
					ans += d[i] // Add the score from the query if it matches
				}
			}
			// Update the maximum score found
			res = max(res, ans)
			return
		}

		// Determine the starting point for the next number to be added
		last_max := 1
		if len(A) > 0 {
			last_max = A[len(A)-1]
		}

		// Iterate through possible values to add to the combination
		for i := last_max; i <= M; i++ {
			rec(append(A, i)) // Recursively call with the new number added to A
	}(make([]int, 0))

	// Start the recursive exploration with an empty list
	rec(make([]int, 0))

	// Print the maximum score found
	fmt.Println(res)
}

// Read the values of N, M, and Q from input
func readInput() (N int, M int, Q int) {
	// Read the first line of input
	line := bufio.NewReader(os.Stdin).ReadString('\n')
	// Split the line into tokens
	tokens := strings.Split(line, " ")
	// Convert the tokens to integers
	N, _ = strconv.Atoi(tokens[0])
	M, _ = strconv.Atoi(tokens[1])
	Q, _ = strconv.Atoi(tokens[2])
	return
}

// Read the query parameters from input
func readQueries(Q int) (a []int, b []int, c []int, d []int) {
	// Initialize lists to hold the query parameters
	a = make([]int, Q)
	b = make([]int, Q)
	c = make([]int, Q)
	d = make([]int, Q)
	// Read the query parameters from input
	for i := 0; i < Q; i++ {
		line := bufio.NewReader(os.Stdin).ReadString('\n')
		tokens := strings.Split(line, " ")
		a[i], _ = strconv.Atoi(tokens[0])
		b[i], _ = strconv.Atoi(tokens[1])
		c[i], _ = strconv.Atoi(tokens[2])
		d[i], _ = strconv.Atoi(tokens[3])
	}
	return
}

// Entry point of the script
func main() {
	// Read the values of N, M, and Q from input
	N, M, Q := readInput()
	// Read the query parameters from input
	a, b, c, d := readQueries(Q)
	// Call the solve function with the parsed input
	solve(N, M, Q, a, b, c, d)
}

// Utility function to find the maximum of two integers
func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

