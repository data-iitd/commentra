
package main

import (
    "bufio"
    "fmt"
    "os"
)

var (
    n, mod int
    memo    = make ([][]map[string]int, n + 1)
)

func ok (last4 string) bool {
    for i := 0; i < 4; i++ {
        t := []byte(last4)
        if i >= 1 {
            t[i], t[i-1] = t[i-1], t[i]
        }
        if string(t).Count("AGC") >= 1 {
            return false
        }
    }
    return true
}

func dfs (cur int, last3 string) int {
    if _, ok := memo[cur][last3]; ok {
        return memo[cur][last3]
    }
    if cur == n {
        return 1
    }
    ret := 0
    for _, c := range "ACGT" {
        if ok(last3 + string(c)) {
            ret = (ret + dfs(cur + 1, last3[1:] + string(c))) % mod
        }
    }
    memo[cur][last3] = ret
    return ret
}

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    if scanner.Scan() {
        n, _ = fmt.Sscanf(scanner.Text(), "%d")
    }
    mod = 100000007
    memo = make([][]map[string]int, n + 1)
    for i := 0; i <= n; i++ {
        memo[i] = make([]map[string]int, 4)
        for j := 0; j < 4; j++ {
            memo[i][j] = make(map[string]int)
        }
    }
    fmt.Println(dfs(0, "TTT"))
}
