
package main

import "fmt"

func ok(last4 string) bool {
	// Check if the last4 string contains "AGC" more than once
	for i := 0; i < 4; i++ {
		t := []byte(last4)
		if i >= 1 {
			// Swap the current and previous character
			t[i], t[i-1] = t[i-1], t[i]
		}
		if string(t).Count("AGC") >= 1 {
			// If "AGC" is found, return False
			return false
		}
	}
	return true
}

func dfs(cur int, last3 string) int {
	// Check if the result for the current state (cur, last3) is already computed
	if memo[cur][last3] != 0 {
		return memo[cur][last3]
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
			ret = (ret + dfs(cur+1, last3[1:]+string(c))) % mod
		}
	}
	memo[cur][last3] = ret
	return ret
}

func main() {
	// Read the input value for n
	var n int
	fmt.Scan(&n)
	mod := 1000000007
	// Initialize the memo dictionary for storing computed results
	memo := make([]map[string]int, n+1)
	for i := 0; i < n+1; i++ {
		memo[i] = make(map[string]int)
	}
	// Print the result of the dfs function starting with last3 as "TTT"
	fmt.Println(dfs(0, "TTT"))
}

