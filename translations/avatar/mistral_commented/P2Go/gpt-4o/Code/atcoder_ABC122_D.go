package main

import (
	"fmt"
)

var memo [][]map[string]int
var n int
var mod = 1000000007

// This function checks if the last 4 nucleotides (last4) contain the sequence "AGC" or not.
// It returns false if it does, and true otherwise.
func ok(last4 string) bool {
	// Iterate through the last 4 nucleotides in reverse order
	for i := 0; i < 4; i++ {
		// Create a slice of runes from the string
		t := []rune(last4)
		if i >= 1 {
			// Swap the positions of the current and previous nucleotides
			t[i], t[i-1] = t[i-1], t[i]
		}

		// Check if the swapped sequence contains "AGC"
		if countSubstr(string(t), "AGC") >= 1 {
			// If yes, return false and exit the function
			return false
		}
	}

	// If no "AGC" sequence is found, return true
	return true
}

// Helper function to count occurrences of a substring in a string
func countSubstr(s, substr string) int {
	count := 0
	for i := 0; i <= len(s)-len(substr); i++ {
		if s[i:i+len(substr)] == substr {
			count++
		}
	}
	return count
}

// This function performs Depth-First Search (DFS) to find the number of valid sequences
func dfs(cur int, last3 string) int {
	// Memoization table to store the results of subproblems
	if val, exists := memo[cur][last3]; exists {
		// If the subproblem has already been solved, return the stored result
		return val
	}

	// Base case: If we have reached the end of the sequence, return 1
	if cur == n {
		return 1
	}

	// Initialize the result to 0
	ret := 0

	// Iterate through all possible nucleotides (A, C, G, T)
	for _, c := range "ACGT" {
		// Check if the next nucleotide can be added to the last 3 nucleotides
		if ok(last3 + string(c)) {
			// If yes, recursively call dfs with the updated last 3 nucleotides and the new current index
			ret = (ret + dfs(cur+1, last3[1:] + string(c))) % mod
		}
	}

	// Store the result in the memoization table and return it
	memo[cur][last3] = ret
	return ret
}

func main() {
	// Read the input: the number of nucleotides (n)
	fmt.Scan(&n)

	// Initialize the memoization table with empty maps
	memo = make([][]map[string]int, n+1)
	for i := range memo {
		memo[i] = make([]map[string]int, 0)
	}

	// Perform DFS and print the result
	fmt.Println(dfs(0, "TTT"))
}

// <END-OF-CODE>
