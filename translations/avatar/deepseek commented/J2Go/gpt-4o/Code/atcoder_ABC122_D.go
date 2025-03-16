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

func (m *Main) isOK(last3 string) bool {
	if containsAGC(last3) {
		return false
	}
	for i := 0; i < 3; i++ {
		// Create a new string by swapping characters
		vals := []rune(last3)
		vals[i], vals[i+1] = vals[i+1], vals[i]
		if containsAGC(string(vals)) {
			return false
		}
	}
	return true
}

func containsAGC(s string) bool {
	return len(s) >= 3 && (s[0:3] == 'A' && s[1] == 'G' && s[2] == 'C')
}

func (m *Main) dfs(current int, last3 string) int64 {
	if val, exists := memo[current][last3]; exists {
		return val
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
