package main

import (
	"fmt"
)

func ok(last4 string) bool {
	// Check if the last 4 characters contain the substring 'AGC'
	for i := 0; i < 4; i++ {
		// Create a slice from the last4 string to allow swapping
		t := []rune(last4)
		// Swap the current character with the previous one if not the first character
		if i >= 1 {
			t[i], t[i-1] = t[i-1], t[i]
		}
		// If 'AGC' is found in the modified string, return false
		if string(t) == "AGC" || string(t) == "GAC" || string(t) == "ACG" {
			return false
		}
	}
	// If 'AGC' is not found in any of the permutations, return true
	return true
}

func dfs(cur int, last3 string, memo map[string]int, n int, mod int) int {
	// Check if the result for the current state is already computed
	if val, exists := memo[last3]; exists {
		return val
	}
	// If we have reached the end of the sequence, return 1 (valid sequence found)
	if cur == n {
		return 1
	}
	ret := 0
	// Iterate through each possible character 'A', 'C', 'G', 'T'
	for _, c := range "ACGT" {
		// Check if adding the current character keeps the sequence valid
		if ok(last3 + string(c)) {
			// Recursively call dfs for the next position with the updated last3
			ret = (ret + dfs(cur+1, last3[1:]+string(c), memo, n, mod)) % mod
		}
	}
	// Store the computed result in the memoization table
	memo[last3] = ret
	return ret
}

func main() {
	// Read the length of the sequence from input
	var n int
	fmt.Scan(&n)
	// Define the modulus for the result
	mod := 1000000007
	// Initialize the memoization table
	memo := make(map[string]int)
	// Start the depth-first search with the initial state
	result := dfs(0, "TTT", memo, n, mod)
	fmt.Println(result)
}
