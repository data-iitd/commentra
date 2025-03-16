package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1000000007

var TOKENS = []string{"A", "C", "G", "T"}

func main() {
	var ins Main
	ins.readInput()
	result := ins.calc()
	fmt.Println(result)
}

type Main struct {
	N      int
	memo   []map[string]int
}

func (m *Main) readInput() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &m.N)
	m.memo = make([]map[string]int, m.N+1)
	for i := range m.memo {
		m.memo[i] = make(map[string]int)
	}
}

func (m *Main) calc() int {
	return m.dfs(0, "TTT")
}

func (m *Main) isOK(last4 string) bool {
	if contains(last4, "AGC") {
		return false
	}
	for i := 0; i < 3; i++ {
		chars := []rune(last4)
		chars[i], chars[i+1] = chars[i+1], chars[i]
		if contains(string(chars), "AGC") {
			return false
		}
	}
	return true
}

func (m *Main) dfs(current int, last3 string) int {
	if val, ok := m.memo[current][last3]; ok {
		return val
	}
	if current == m.N {
		return 1
	}
	var result int
	for _, c := range TOKENS {
		if m.isOK(last3 + c) {
			result = (result + m.dfs(current+1, last3[1:]+c)) % MOD
		}
	}
	m.memo[current][last3] = result
	return result
}

func contains(s, substr string) bool {
	return len(s) >= len(substr) && s[len(s)-len(substr):] == substr
}

