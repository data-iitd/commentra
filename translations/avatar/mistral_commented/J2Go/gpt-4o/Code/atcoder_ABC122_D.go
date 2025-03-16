package main

import (
	"fmt"
)

const MOD = 1000000007

var TOKENS = []string{"A", "C", "G", "T"}
var memo [][]map[string]int64
var N int

func main() {
	fmt.Scan(&N) // Reading the number of test cases

	memo = make([][]map[string]int64, N+1) // Initializing a 2D map to store the results of subproblems
	for i := range memo {
		memo[i] = make([]map[string]int64, 1)
		memo[i][0] = make(map[string]int64)
	}

	result := calc() // Calling the function to calculate the result
	fmt.Println(result) // Printing the result
}

func calc() int64 {
	return dfs(0, "TTT") // Calling the recursive function to calculate the result
}

// Checking if the last 4 nucleotides form an invalid sequence
func isOK(last4 string) bool {
	if containsAGC(last4) { // If the sequence contains "AGC", it's invalid
		return false
	}

	for i := 0; i < 3; i++ { // Checking all possible pairs of adjacent nucleotides
		vals := []rune(last4)
		vals[i], vals[i+1] = vals[i+1], vals[i] // Swapping adjacent nucleotides
		s := string(vals)

		if containsAGC(s) { // If the pair contains "AGC", it's invalid
			return false
		}
	}

	return true // If no invalid sequence is found, the last 4 nucleotides are valid
}

func containsAGC(s string) bool {
	return len(s) >= 3 && (s[0:3] == "AGC")
}

func dfs(current int, last3 string) int64 {
	if val, exists := memo[current][0][last3]; exists { // If the result for the current sub-sequence and last 3 nucleotides is already calculated
		return val
	}

	if current == N { // If we reach the end of the sequence, the result is 1
		return 1
	}

	result := int64(0) // Initializing the result to 0

	for _, c := range TOKENS { // Iterating through all possible next nucleotides
		if isOK(last3 + c) { // If the next nucleotide and the current sequence form a valid sequence
			result = (result + dfs(current+1, last3[1:] + c)) % MOD // Recursively calculating the result for the next sub-sequence
		}
	}

	memo[current][0][last3] = result // Storing the result for the current sub-sequence and last 3 nucleotides
	return result // Returning the result
}
