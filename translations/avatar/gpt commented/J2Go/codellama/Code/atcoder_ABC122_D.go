package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Number of characters to generate
var N int
// Modulus value for large number calculations
var MOD int64 = 1000000007
// Possible tokens (characters) to use
var TOKENS = []string{"A", "C", "G", "T"}
// Memoization array to store computed results
var memo []map[string]int64

// Constructor to initialize the class
func init() {
	// Create a scanner to read input
	scanner := bufio.NewScanner(os.Stdin)
	// Read the number of characters to generate
	scanner.Scan()
	N, _ = strconv.Atoi(scanner.Text())
	// Close the scanner
	scanner.Close()
	// Initialize the memoization array
	memo = make([]map[string]int64, N+1)
	for i := 0; i < len(memo); i++ {
		// Initialize each entry in the memoization array with a new HashMap
		memo[i] = make(map[string]int64)
	}
}

// Method to calculate the total valid sequences
func calc() int64 {
	// Start the depth-first search with the initial state
	return dfs(0, "TTT")
}

// Method to check if the last 4 characters are valid
func isOK(last4 string) bool {
	// Check if the last 4 characters contain "AGC"
	if strings.Contains(last4, "AGC") {
		return false
	}
	// Check all permutations of the last 4 characters
	for i := 0; i < 3; i++ {
		vals := []byte(last4)
		// Swap characters to create a new permutation
		vals[i], vals[i+1] = vals[i+1], vals[i]
		s := string(vals)
		// Check if the new permutation contains "AGC"
		if strings.Contains(s, "AGC") {
			return false
		}
	}
	// If no invalid sequences found, return true
	return true
}

// Depth-first search method to explore all possible sequences
func dfs(current int, last3 string) int64 {
	// Check if the result is already computed and stored in memo
	if memo[current][last3] != 0 {
		return memo[current][last3]
	}
	// Base case: if the current length equals N, return 1 (valid sequence)
	if current == N {
		return 1
	}
	// Variable to accumulate the result
	result := int64(0)
	// Iterate through each possible token
	for _, c := range TOKENS {
		// Check if adding the token to the last 3 characters is valid
		if isOK(last3 + c) {
			// Recursively call dfs for the next character
			result = (result + dfs(current+1, last3[1:]+c)) % MOD
		}
	}
	// Store the computed result in memoization array
	memo[current][last3] = result
	return result
}

// Main method to execute the program
func main() {
	// Print the result of the calculation
	fmt.Println(calc())
}

// 