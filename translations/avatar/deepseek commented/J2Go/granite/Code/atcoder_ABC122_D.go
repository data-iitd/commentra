
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

const MOD = 1000000007

var tokens = []string{"A", "C", "G", "T"}
var memo = make([]map[string]int64, 100001)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    const initialBufSize = 4096
    const maxBufSize = 1000000
    scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
    scanner.Split(bufio.ScanWords)
    var n int
    scanner.Scan()
    n, _ = strconv.Atoi(scanner.Text())

    for i := 0; i <= n; i++ {
        memo[i] = make(map[string]int64)
    }

    fmt.Println(dfs(n, "TTT"))
}

func isOK(last4 string) bool {
    if strings.Contains(last4, "AGC") {
        return false
    }
    for i := 0; i < 3; i++ {
        chars := []byte(last4)
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
    if current == 0 {
        return 1
    }
    result := int64(0)
    for _, c := range tokens {
        if isOK(last3 + c) {
            result = (result + dfs(current-1, last3[1:]+c)) % MOD
        }
    }
    memo[current][last3] = result
    return result
}

// 