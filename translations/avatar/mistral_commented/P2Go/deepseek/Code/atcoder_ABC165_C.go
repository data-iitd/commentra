package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to solve the problem
func solve(N int, M int, Q int, a []int, b []int, c []int, d []int) {
	// Initialize result to 0
	var res int

	// Helper function to calculate the answer recursively
	var rec func([]int)
	rec = func(A []int) {
		// Base case: if all elements of A are placed, calculate the answer
		if len(A) == N {
			ans := 0
			for i := 0; i < Q; i++ {
				// Check if the condition is satisfied
				if A[b[i]-1]-A[a[i]-1] == c[i] {
					ans += d[i]
				}
			}
			// Update the result with the maximum answer
			if ans > res {
				res = ans
			}
			return
		}

		// Recursive call: try placing elements from last_max to M
		last_max := 1
		if len(A) > 0 {
			last_max = A[len(A)-1]
		}
		for i := last_max; i <= M; i++ {
			rec(append(A, i))
		}
	}

	// Call the helper function with an empty list
	rec([]int{})

	// Print the result
	fmt.Println(res)
}

// Main function to read input and call the solve function
func main() {
	// Create a new scanner to read from standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the first line to get N
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())

	// Read the second line to get M and Q
	scanner.Scan()
	M, _ := strconv.Atoi(scanner.Text())
	Q, _ := strconv.Atoi(scanner.Text())

	// Initialize arrays a, b, c, and d
	a := make([]int, Q)
	b := make([]int, Q)
	c := make([]int, Q)
	d := make([]int, Q)

	// Read the next Q lines to fill the arrays
	for i := 0; i < Q; i++ {
		scanner.Scan()
		fields := bufio.ScanWords
		scanner.Split(fields)
		a[i], _ = strconv.Atoi(scanner.Text())
		b[i], _ = strconv.Atoi(scanner.Text())
		c[i], _ = strconv.Atoi(scanner.Text())
		d[i], _ = strconv.Atoi(scanner.Text())
	}

	// Call the solve function with the given input
	solve(N, M, Q, a, b, c, d)
}

