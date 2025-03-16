package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N int
	var MOD int64 = 1000000007
	var TOKENS []string = []string{"A", "C", "G", "T"}
	var memo []map[string]int64
	var result int64
	var current int
	var last3 string
	var c string
	var s string
	var vals []rune
	var i int
	var last4 string
	var ok bool
	var in *bufio.Scanner
	in = bufio.NewScanner(os.Stdin)
	in.Scan()
	N, _ = strconv.Atoi(in.Text())
	in.Close()
	memo = make([]map[string]int64, N+1)
	for i = 0; i < len(memo); i++ {
		memo[i] = make(map[string]int64)
	}
	result = dfs(0, "TTT")
	fmt.Println(result)
}

func dfs(current int, last3 string) int64 {
	if memo[current][last3]!= 0 {
		return memo[current][last3]
	}
	if current == N {
		return 1
	}
	result := int64(0)
	for _, c = range TOKENS {
		if isOK(last3 + c) {
			result = (result + dfs(current+1, last3[1:len(last3)]+c)) % MOD
		}
	}
	memo[current][last3] = result
	return result
}

func isOK(last4 string) bool {
	if strings.Contains(last4, "AGC") {
		return false
	}
	for i = 0; i < 3; i++ {
		vals = []rune(last4)
		vals[i], vals[i+1] = vals[i+1], vals[i]
		s = string(vals)
		if strings.Contains(s, "AGC") {
			return false
		}
	}
	return true
}

