
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const MOD = 1000000007

var (
	TOKENS = []string{"A", "C", "G", "T"}
	N      int
	memo   = make([]map[string]int64, N+1)
)

func init() {
	for i := 0; i < N+1; i++ {
		memo[i] = make(map[string]int64)
	}
}

func isOK(last4 string) bool {
	if strings.Contains(last4, "AGC") {
		return false
	}
	for i := 0; i < 3; i++ {
		vals := []byte(last4)
		vals[i], vals[i+1] = vals[i+1], vals[i]
		s := string(vals)
		if strings.Contains(s, "AGC") {
			return false
		}
	}
	return true
}

func dfs(current int, last3 string) int64 {
	if v, ok := memo[current][last3]; ok {
		return v
	}
	if current == N {
		return 1
	}
	var result int64
	for _, c := range TOKENS {
		if isOK(last3 + c) {
			result = (result + dfs(current+1, last3[1:]+c)) % MOD
		}
	}
	memo[current][last3] = result
	return result
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		N, _ = strconv.Atoi(scanner.Text())
	}
	fmt.Println(dfs(0, "TTT"))
}

