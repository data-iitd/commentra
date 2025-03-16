

package main

import (
  "bufio"
  "fmt"
  "os"
  "strconv"
  "strings"
)

const MOD = 1000000007

var (
  N int
  TOKENS = []string{"A", "C", "G", "T"}
  memo = make ([][]map[string]int64, N+1)
)

func main() {
  reader := bufio.NewReader(os.Stdin)
  fmt.Fscanf(reader, "%d\n", &N)

  for i := 0; i <= N; i++ {
    memo[i] = make(map[string]int64)
  }

  fmt.Println(dfs(0, "TTT"))
}

func isOK(last4 string) bool {
  if strings.Contains(last4, "AGC") {
    return false
  }

  for i := 0; i < 3; i++ {
    chars := []rune(last4)
    chars[i], chars[i+1] = chars[i+1], chars[i]
    s := string(chars)

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