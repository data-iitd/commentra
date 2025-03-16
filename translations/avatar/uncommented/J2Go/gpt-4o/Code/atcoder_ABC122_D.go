package main

import (
	"fmt"
)

const MOD = 1000000007

var TOKENS = []string{"A", "C", "G", "T"}
var memo [][]map[string]int64
var N int

func isOK(last4 string) bool {
	if containsAGC(last4) {
		return false
	}
	for i := 0; i < 3; i++ {
		vals := []rune(last4)
		vals[i], vals[i+1] = vals[i+1], vals[i]
		s := string(vals)
		if containsAGC(s) {
			return false
		}
	}
	return true
}

func containsAGC(s string) bool {
	return len(s) >= 3 && (s[0:3] == "AGC" || s[1:4] == "AGC")
}

func dfs(current int, last3 string) int64 {
	if val, exists := memo[current][last3]; exists {
		return val
	}
	if current == N {
		return 1
	}
	result := int64(0)
	for _, c := range TOKENS {
		if isOK(last3 + c) {
			result = (result + dfs(current+1, last3[1:] + c)) % MOD
		}
	}
	memo[current][last3] = result
	return result
}

func calc() int64 {
	return dfs(0, "TTT")
}

func main() {
	fmt.Scan(&N)
	memo = make([][]map[string]int64, N+1)
	for i := range memo {
		memo[i] = make(map[string]int64)
	}
	fmt.Println(calc())
}

// <END-OF-CODE>
