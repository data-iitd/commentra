package main

import (
	"fmt"
)

const MOD = 1000000007

var TOKENS = []string{"A", "C", "G", "T"}
var memo [][]map[string]int64

type Main struct {
	N int
}

func (m *Main) isOK(last4 string) bool {
	if containsAGC(last4) {
		return false
	}
	for i := 0; i < 3; i++ {
		vals := []rune(last4)
		vals[i], vals[i+1] = vals[i+1], vals[i] // Swap characters
		if containsAGC(string(vals)) {
			return false
		}
	}
	return true
}

func containsAGC(s string) bool {
	return len(s) >= 3 && (s[0:3] == "AGC" || s[1:4] == "AGC")
}

func (m *Main) dfs(current int, last3 string) int64 {
	if _, exists := memo[current][last3]; exists {
		return memo[current][last3]
	}
	if current == m.N {
		return 1
	}
	result := int64(0)
	for _, c := range TOKENS {
		if m.isOK(last3 + c) {
			result = (result + m.dfs(current+1, last3[1:] + c)) % MOD
		}
	}
	memo[current][last3] = result
	return result
}

func (m *Main) calc() int64 {
	return m.dfs(0, "TTT")
}

func main() {
	var n int
	fmt.Scan(&n)
	m := Main{N: n}
	memo = make([][]map[string]int64, n+1)
	for i := range memo {
		memo[i] = make(map[string]int64)
	}
	fmt.Println(m.calc())
}

// <END-OF-CODE>
