package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1000000007

var TOKENS = []string{"A", "C", "G", "T"}

type Main struct {
	N     int
	memo  []map[string]int
}

func NewMain() *Main {
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)
	in.Scan()
	N := toInt(in.Text())
	in.Close()

	memo := make([]map[string]int, N+1)
	for i := 0; i < len(memo); i++ {
		memo[i] = make(map[string]int)
	}

	return &Main{N, memo}
}

func (m *Main) calc() int {
	return m.dfs(0, "TTT")
}

func (m *Main) isOK(last4 string) bool {
	if contains(last4, "AGC") {
		return false
	}

	for i := 0; i < 3; i++ {
		vals := []rune(last4)
		vals[i] = rune(last4[i+1])
		vals[i+1] = rune(last4[i])
		s := string(vals)

		if contains(s, "AGC") {
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

	result := 0

	for _, c := range TOKENS {
		if m.isOK(last3 + c) {
			result = (result + m.dfs(current+1, last3[1:]+c)) % MOD
		}
	}

	m.memo[current][last3] = result
	return result
}

func toInt(s string) int {
	var num int
	for _, c := range s {
		num = num*10 + int(c-'0')
	}
	return num
}

func contains(s, substr string) bool {
	return len(s) >= len(substr) && s[len(s)-len(substr):] == substr
}

func main() {
	ins := NewMain()
	fmt.Println(ins.calc())
}

