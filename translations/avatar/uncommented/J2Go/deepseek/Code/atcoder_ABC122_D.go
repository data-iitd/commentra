package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1000000007

var TOKENS = []string{"A", "C", "G", "T"}

type Main struct {
	N    int
	memo []map[string]int
}

func NewMain() *Main {
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)
	in.Scan()
	N := parseInt(in.Text())
	in.Scan()
	in.Close()
	memo := make([]map[string]int, N+1)
	for i := 0; i < len(memo); i++ {
		memo[i] = make(map[string]int)
	}
	return &Main{N, memo}
}

func (m *Main) Calc() int {
	return m.dfs(0, "TTT")
}

func (m *Main) isOK(last4 string) bool {
	if containsAGC(last4) {
		return false
	}
	for i := 0; i < 3; i++ {
		vals := []rune(last4)
		vals[i], vals[i+1] = vals[i+1], vals[i]
		if containsAGC(string(vals)) {
			return false
		}
	}
	return true
}

func containsAGC(s string) bool {
	return s == "AGC" || s == "GAC" || s == "ACG" || s == "AGAC" || s == "AGGC" || s == "ATC"
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

func parseInt(s string) int {
	var result int
	for _, c := range s {
		result = result*10 + int(c-'0')
	}
	return result
}

func main() {
	ins := NewMain()
	fmt.Println(ins.Calc())
}

