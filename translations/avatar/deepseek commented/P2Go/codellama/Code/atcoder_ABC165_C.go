
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solve(N int, M int, Q int, a []int, b []int, c []int, d []int) {
	res := 0 // Initialize the result variable to store the maximum score

	// Define the recursive function to generate sequences
	var rec func(A []int)
	rec = func(A []int) {
		if len(A) == N { // If the sequence length is equal to N
			ans := 0 // Initialize the answer for this sequence
			for i := 0; i < Q; i++ { // Iterate over all constraints
				if A[b[i]-1]-A[a[i]-1] == c[i] { // Check if the constraint is satisfied
					ans += d[i] // Add the value of the constraint to the answer
				}
			}
			res = max(res, ans) // Update the result with the maximum score
			return
		}
		last_max := 1 // Determine the starting point for the next number
		if len(A) > 0 {
			last_max = A[len(A)-1]
		}
		for i := last_max; i <= M; i++ { // Generate the next number in the sequence
			rec(append(A, i))
		}
	}

	rec([]int{}) // Start the recursive function with an empty list
	fmt.Println(res) // Print the result
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	tokens := strings.Split(os.Args[1], " ") // Read input line by line
	N, _ := strconv.Atoi(tokens[0]) // Read the value of N
	M, _ := strconv.Atoi(tokens[1]) // Read the value of M
	Q, _ := strconv.Atoi(tokens[2]) // Read the value of Q
	a := make([]int, Q) // Read the list a
	b := make([]int, Q) // Read the list b
	c := make([]int, Q) // Read the list c
	d := make([]int, Q) // Read the list d
	for i := 0; i < Q; i++ {
		a[i], _ = strconv.Atoi(tokens[3+i])
		b[i], _ = strconv.Atoi(tokens[3+Q+i])
		c[i], _ = strconv.Atoi(tokens[3+2*Q+i])
		d[i], _ = strconv.Atoi(tokens[3+3*Q+i])
	}
	solve(N, M, Q, a, b, c, d) // Call the solve function with the input values
}

