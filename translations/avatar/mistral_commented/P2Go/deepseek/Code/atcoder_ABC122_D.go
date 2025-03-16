package main

import (
	"fmt"
)

// This function checks if the last 4 nucleotides (last4) contain the sequence "AGC" or not.
// It returns false if it does, and true otherwise.
// Input: last4 (a list of 4 nucleotides)
// Output: A boolean value
func ok(last4 []rune) bool {
	// Iterate through the last 4 nucleotides in reverse order
	for i := 0; i < 4; i++ {
		// Swap the positions of the current and previous nucleotides
		t := append([]rune(nil), last4...)
		if i >= 1 {
			t[i], t[i-1] = t[i-1], t[i]
		}

		// Check if the swapped sequence contains "AGC"
		if containsAGC(string(t)) {
			// If yes, return false and exit the function
			return false
		}
	}

	// If no "AGC" sequence is found, return true
	return true
}

// This function checks if the given string contains the sequence "AGC"
func containsAGC(s string) bool {
	return s == "AGC" || s == "ACG" || s == "GAC"
}

// This function performs Depth-First Search (DFS) to find the number of valid sequences
// Input: cur (the current index), last3 (the last 3 nucleotides)
// Output: An integer value representing the number of valid sequences
var memo = make(map[int]map[string]int)
var mod = int(1e9 + 7)

func dfs(cur int, last3 string) int {
	// Memoization table to store the results of subproblems
	if _, exists := memo[cur][last3]; exists {
		// If the subproblem has already been solved, return the stored result
		return memo[cur][last3]
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
		if ok(append([]rune(nil), []rune(last3+string(c)...)) {
			// If yes, recursively call dfs with the updated last 3 nucleotides and the new current index
			ret = (ret + dfs(cur+1, last3[1:]+string(c))) % mod
		}
	}

	// Store the result in the memoization table and return it
	if memo[cur] == nil {
		memo[cur] = make(map[string]int)
	}
	memo[cur][last3] = ret
	return ret
}

// Read the input: the number of nucleotides (n)
var n int
fmt.Scan(&n)

// Initialize the memoization table with empty dictionaries
for i := 0; i <= n; i++ {
	memo[i] = make(map[string]int)
}

// Perform DFS and print the result
fmt.Println(dfs(0, "TTT"))

