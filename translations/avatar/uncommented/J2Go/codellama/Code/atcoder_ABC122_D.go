
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var N int
	var MOD int64 = 1000000007
	var TOKENS = []string{"A", "C", "G", "T"}
	var memo []map[string]int64
	var in = os.Args[1:]
	N, _ = strconv.Atoi(in[0])
	memo = make([]map[string]int64, N+1)
	for i := 0; i < len(memo); i++ {
		memo[i] = make(map[string]int64)
	}
	fmt.Println(calc())
}

func calc() int64 {
	return dfs(0, "TTT")
}

func isOK(last4 string) bool {
	if last4.Contains("AGC") {
		return false
	}
	for i := 0; i < 3; i++ {
		vals := []rune(last4)
		vals[i], vals[i+1] = vals[i+1], vals[i]
		s := string(vals)
		if s.Contains("AGC") {
			return false
		}
	}
	return true
}

func dfs(current int, last3 string) int64 {
	if memo[current][last3] != 0 {
		return memo[current][last3]
	}
	if current == N {
		return 1
	}
	result := int64(0)
	for _, c := range TOKENS {
		if isOK(last3 + c) {
			result = (result + dfs(current+1, last3[1:]+c)) % MOD
		}
	}
	memo[current][last3] = result
	return result
}

// 