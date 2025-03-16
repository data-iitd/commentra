package main

import (
	"fmt"
	"strings"
)

const mod = 1000000007

var memo [][]map[string]int

func ok(last4 string) bool {
	for i := 0; i < 4; i++ {
		t := []rune(last4)
		if i >= 1 {
			// Swap the current and previous character
			t[i], t[i-1] = t[i-1], t[i]
		}
		if strings.Count(string(t), "AGC") >= 1 {
			// If "AGC" is found, return false
			return false
		}
	}
	return true
}

func dfs(cur int, last3 string, n int) int {
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
			ret = (ret + dfs(cur+1, last3[1:]+string(c), n)) % mod
		}
	}
	memo[cur][last3] = ret
	return ret
}

func main() {
	var n int
	// Read the input value for n
	fmt.Scan(&n)
	// Initialize the memo dictionary for storing computed results
	memo = make([][]map[string]int, n+1)
	for i := range memo {
		memo[i] = make(map[string]int)
	}
	// Print the result of the dfs function starting with last3 as "TTT"
	fmt.Println(dfs(0, "TTT", n))
}

// <END-OF-CODE>
