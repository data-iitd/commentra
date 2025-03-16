
package main

import "fmt"

func ok(last4 []byte) bool {
    for i := 0; i < 4; i++ {
        if i >= 1 {
            last4[i], last4[i-1] = last4[i-1], last4[i]
        }
        if string(last4).Count("AGC") >= 1 {
            return false
        }
    }
    return true
}

func dfs(cur, last3 string) int {
    if last3, ok := memo[cur][last3]; ok {
        return last3
    }
    if cur == n {
        return 1
    }
    ret := 0
    for _, c := range "ACGT" {
        if ok(append([]byte(last3[1:]), c...)) {
            ret = (ret + dfs(cur+1, last3[1:]+string(c))) % mod
        }
    }
    memo[cur][last3] = ret
    return ret
}

func main() {
    var n int
    fmt.Scanf("%d", &n)
    memo = make([]map[string]int, n+1)
    for i := 0; i < n+1; i++ {
        memo[i] = make(map[string]int)
    }
    mod := int(1e9) + 7
    fmt.Println(dfs(0, "TTT"))
}

