
const mod = 1e9 + 7
var l string
var n int
var dp [100001][2]int64
func main() {
    fmt.Scan(&l)
    n = len(l)
    dp[0][0] = 1
    for i, c := range l {
        if c == '0' {
            dp[i+1][0] += dp[i][0]
            dp[i+1][1] += dp[i][1] * 3
        } else {
            dp[i+1][0] += dp[i][0] * 2
            dp[i+1][1] += dp[i][0]
            dp[i+1][1] += dp[i][1] * 3
        }
        dp[i+1][0] %= mod
        dp[i+1][1] %= mod
    }
    fmt.Println((dp[n][0] + dp[n][1]) % mod)
}
