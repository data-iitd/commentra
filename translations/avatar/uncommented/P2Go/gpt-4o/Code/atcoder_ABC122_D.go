package main

import (
	"fmt"
	"strings"
)

var mod = int(1e9 + 7)
var memo [][]map[string]int

func ok(last4 string) bool {
	for i := 0; i < 4; i++ {
		t := []rune(last4)
		if i >= 1 {
			t[i], t[i-1] = t[i-1], t[i]
		}
		if strings.Count(string(t), "AGC") >= 1 {
			return false
		}
	}
	return true
}

func dfs(cur int, last3 string, n int) int {
	if val, exists := memo[cur][last3]; exists {
		return val
	}
	if cur == n {
		return 1
	}
	ret := 0
	for _, c := range "ACGT" {
		if ok(last3 + string(c)) {
			ret = (ret + dfs(cur+1, last3[1:]+string(c), n)) % mod
		}
	}
	memo[cur][last3] = ret
	return ret
}

func main() {
	var n int
	fmt.Scan(&n)
	memo = make([][]map[string]int, n+1)
	for i := range memo {
		memo[i] = make(map[string]int)
	}
	fmt.Println(dfs(0, "TTT", n))
}

// <END-OF-CODE>
