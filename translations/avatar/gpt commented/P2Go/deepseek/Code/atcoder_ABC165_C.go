package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func solve(N int, M int, Q int, a []int, b []int, c []int, d []int) {
	// Initialize the result variable to store the maximum score
	var res int
	
	// Recursive function to explore combinations of numbers
	var rec func([]int)
	rec = func(A []int) {
		// Base case: if the length of A equals N, calculate the score
		if len(A) == N {
			ans := 0
			// Check each query to see if it contributes to the score
			for i := 0; i < Q; i++ {
				if A[b[i]-1] - A[a[i]-1] == c[i] {
					ans += d[i] // Add the score from the query if it matches
				}
			}
			// Update the maximum score found
			if ans > res {
				res = ans
			}
			return
		}
		
		// Determine the starting point for the next number to be added
		lastMax := 1
		if len(A) > 0 {
			lastMax = A[len(A)-1]
		}
		
		// Iterate through possible values to add to the combination
		for i := lastMax; i <= M; i++ {
			rec(append(A, i)) // Recursively call with the new number added to A
		}
	}
	
	// Start the recursive exploration with an empty list
	rec([]int{})
	
	// Print the maximum score found
	fmt.Println(res)
}

func main() {
	// Create a new scanner to read input
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the first line to get N, M, and Q
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	M, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	Q, _ := strconv.Atoi(scanner.Text())
	
	// Initialize slices to hold the query parameters
	a := make([]int, Q)
	b := make([]int, Q)
	c := make([]int, Q)
	d := make([]int, Q)
	
	// Read the query parameters from input
	for i := 0; i < Q; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		b[i], _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		c[i], _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		d[i], _ = strconv.Atoi(scanner.Text())
	}
	
	// Call the solve function with the parsed input
	solve(N, M, Q, a, b, c, d)
}

