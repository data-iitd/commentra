package main

import (
	"fmt"
)

func ok(last4 string) bool {
	// Check if the last4 string contains "AGC" more than once
	for i := 0; i < 4; i++ {
		t := []rune(last4)
		if i >= 1 {
			// Swap the current and previous character
			t[i], t[i-1] = t[i-1], t[i]
		}
		if count := strings.Count(string(t), "AGC"); count >= 1 {
			// If "AGC" is found, return false
			return false
		}
	}
	return true
}

func dfs(cur int, last3 string) int {
	// Check if the result for the current state (cur, last3) is already computed
	if val, exists := memo[cur][last3]; exists {
		return val
	}
	if cur == n {
		// Base case: if current length equals n, return 1 (valid sequence)
		return 1
	}
	ret := 0
	for _, c := range "ACGT" {
		// Check if adding the character c to last3 forms a valid sequence
		if ok(last3 + string(c)) {
			// Recursively call dfs with the next character
			ret = (ret + dfs(cur+1, last3[1:]+"c")) % mod
		}
	}
	memo[cur][last3] = ret
	return ret
}

var n int
var mod int = 1000000007
var memo = make(map[int]map[string]int)

func main() {
	// Read the input value for n
	fmt.Scan(&n)
	// Initialize the memo dictionary for storing computed results
	for i := 0; i <= n; i++ {
		memo[i] = make(map[string]int)
	}
	// Print the result of the dfs function starting with last3 as "TTT"
	fmt.Println(dfs(0, "TTT"))
}
