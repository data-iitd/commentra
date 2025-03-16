
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var N int
	scanner.Scan()
	N, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	MOD := int64(1000000007)
	TOKENS := []string{"A", "C", "G", "T"}
	memo := make([]map[string]int64, N+1)
	for i := 0; i < len(memo); i++ {
		memo[i] = make(map[string]int64)
	}
	fmt.Println(dfs(0, "TTT"))
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

func isOK(last4 string) bool {
	if last4 == "AGC" {
		return false
	}
	for i := 0; i < 3; i++ {
		vals := []rune(last4)
		vals[i], vals[i+1] = vals[i+1], vals[i]
		s := string(vals)
		if s == "AGC" {
			return false
		}
	}
	return true
}

