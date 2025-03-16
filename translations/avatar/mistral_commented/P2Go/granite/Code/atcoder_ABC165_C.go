
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
	res := 0

	// Helper function to calculate the answer recursively
	var rec func(A []int)
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
			last_max = A[len(A)-1] + 1
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
	// Function to generate tokens from standard input
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read number of test cases
	N, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()

	// Read number of elements in the array and number of queries
	M, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	Q, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()

	// Read the arrays a, b, c, and d
	a := make([]int, Q)
	b := make([]int, Q)
	c := make([]int, Q)
	d := make([]int, Q)
	for i := 0; i < Q; i++ {
		a[i], _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		b[i], _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		c[i], _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		d[i], _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
	}

	// Call the solve function with the given input
	solve(N, M, Q, a, b, c, d)
}

// End of code