
package main

import (
	"bufio"
	"fmt"
	"os"
)

func ok(last4 string) bool {
	// Check if the last 4 characters contain the substring 'AGC'
	for i := 0; i < 4; i++ {
		// Create a list from the last4 string to allow swapping
		t := []byte(last4)
		// Swap the current character with the previous one if not the first character
		if i >= 1 {
			t[i], t[i-1] = t[i-1], t[i]
		}
		// If 'AGC' is found in the modified string, return False
		if string(t).Count("AGC") >= 1 {
			return false
		}
	}
	// If 'AGC' is not found in any of the permutations, return True
	return true
}

func dfs(cur int, last3 string) int {
	// Check if the result for the current state is already computed
	if v, ok := memo[cur][last3]; ok {
		return v
	}
	// If we have reached the end of the sequence, return 1 (valid sequence found)
	if cur == n {
		return 1
	}
	ret := 0
	// Iterate through each possible character 'A', 'C', 'G', 'T'
	for _, c := range "ACGT" {
		// Check if adding the current character keeps the sequence valid
		if ok(last3+string(c)) {
			// Recursively call dfs for the next position with the updated last3
			ret = (ret + dfs(cur+1, last3[1:]+string(c))) % mod
		}
	}
	// Store the computed result in the memoization table
	memo[cur][last3] = ret
	return ret
}

func main() {
	// Read the length of the sequence from input
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n := len(scanner.Text())
	// Define the modulus for the result
	mod := 100000007
	// Initialize the memoization table
	memo := make([]map[string]int, n+1)
	for i := range memo {
		memo[i] = make(map[string]int)
	}
	// Start the depth-first search with the initial state
	fmt.Println(dfs(0, "TTT"))
}

