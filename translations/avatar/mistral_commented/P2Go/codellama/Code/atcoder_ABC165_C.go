// Package main is the entry point of the program.
package main

// Importing fmt module for printing output.
import "fmt"

// Function to solve the problem
func solve(N int, M int, Q int, a []int, b []int, c []int, d []int) {
	// Initialize result to 0
	res := 0

	// Helper function to calculate the answer recursively
	var rec func(A []int)
	rec = func(A []int) {
		// Nonlocal variable to update the result from the recursive calls
		res := res

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
			res = max(res, ans)
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

// Function to return the maximum of two integers
func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

// Main function to read input and call the solve function
func main() {
	// Function to generate tokens from standard input
	var iterateTokens func()
	iterateTokens = func() {
		var line string
		_, err := fmt.Scanln(&line)
		if err != nil {
			return
		}
		for _, word := range strings.Split(line, " ") {
			yield(word)
		}
	}

	// Read input tokens
	tokens := iterateTokens()

	// Read number of test cases
	N := nextInt(tokens)

	// Read number of elements in the array and number of queries
	M := nextInt(tokens)
	Q := nextInt(tokens)

	// Read the arrays a, b, c, and d
	a := make([]int, Q)
	b := make([]int, Q)
	c := make([]int, Q)
	d := make([]int, Q)
	for i := 0; i < Q; i++ {
		a[i] = nextInt(tokens)
		b[i] = nextInt(tokens)
		c[i] = nextInt(tokens)
		d[i] = nextInt(tokens)
	}

	// Call the solve function with the given input
	solve(N, M, Q, a, b, c, d)
}

// Function to read the next integer from the input
func nextInt(tokens *[]string) int {
	// Read the next token from the input
	token := nextToken(tokens)

	// Convert the token to an integer
	num, err := strconv.Atoi(token)
	if err != nil {
		panic(err)
	}

	// Return the integer
	return num
}

// Function to read the next token from the input
func nextToken(tokens *[]string) string {
	// If there are no more tokens, read the next line from the input
	if len(*tokens) == 0 {
		var line string
		_, err := fmt.Scanln(&line)
		if err != nil {
			panic(err)
		}
		*tokens = strings.Split(line, " ")
	}

	// Return the next token
	token := (*tokens)[0]
	*tokens = (*tokens)[1:]
	return token
}

// Function to yield the next token from the input
func yield(token string) {
	// Print the token
	fmt.Println(token)
}

// 