package main

import (
	"fmt"
	"strings"
)

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

func dfs(cur int, last3 string, memo map[int]map[string]int, n int, mod int) int {
	if _, exists := memo[cur][last3]; exists {
		return memo[cur][last3]
	}
	if cur == n {
		return 1
	}
	ret := 0
	for _, c := range "ACGT" {
		if ok(last3 + string(c)) {
			ret = (ret + dfs(cur+1, last3[1:]+string(c), memo, n, mod)) % mod
		}
	}
	memo[cur][last3] = ret
	return ret
}

func main() {
	var n int
	fmt.Scan(&n)
	mod := 1000000007
	memo := make(map[int]map[string]int)
	for i := 0; i <= n; i++ {
		memo[i] = make(map[string]int)
	}
	fmt.Println(dfs(0, "TTT", memo, n, mod))
}

