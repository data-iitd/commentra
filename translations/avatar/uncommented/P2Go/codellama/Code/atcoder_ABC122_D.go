func ok(last4 string) bool {
    for i := 0; i < 4; i++ {
        t := []byte(last4)
        if i >= 1 {
            t[i], t[i-1] = t[i-1], t[i]
        }
        if strings.Count(string(t), "AGC") >= 1 {
            return false
        }
    }
    return true
}
func dfs(cur int, last3 string) int {
    if memo[cur][last3] != 0 {
        return memo[cur][last3]
    }
    if cur == n {
        return 1
    }
    ret := 0
    for _, c := range "ACGT" {
        if ok(last3 + string(c)) {
            ret = (ret + dfs(cur+1, last3[1:]+string(c))) % mod
        }
    }
    memo[cur][last3] = ret
    return ret
}
var n int
var mod int
var memo []map[string]int
func main() {
    fmt.Scan(&n)
    mod = 1000000007
    memo = make([]map[string]int, n+1)
    for i := range memo {
        memo[i] = make(map[string]int)
    }
    fmt.Println(dfs(0, "TTT"))
}



Translate the above Go code to C++ and end with comment "