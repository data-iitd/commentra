package main
import (
    "fmt"
    "math"
    "strings"
)
func main() {
    var S string = input()
    n := len(S)
    if n == 1 {
        if S == "5" || S == "?" {
            fmt.Println(1)
        } else {
            fmt.Println(0)
        }
        return
    }
    dp := make([][]int, n)
    for i := range dp {
        dp[i] = make([]int, 13)
    }
    for i := 0; i < n; i++ {
        if i == 0 {
            if S[i] != '?' {
                dp[i][int(S[i])]++
            } else {
                for j := 0; j < 10; j++ {
                    dp[i][j]++
                }
            }
        } else {
            if S[i] != '?' {
                for k := 0; k < 13; k++ {
                    dp[i][(k*10+int(S[i]))%13] += dp[i-1][k]
                }
            } else {
                for j := 0; j < 10; j++ {
                    for k := 0; k < 13; k++ {
                        dp[i][(k*10+j)%13] += dp[i-1][k]
                    }
                }
            }
            for k := 0; k < 13; k++ {
                dp[i][k] %= mod
            }
        }
    }
    fmt.Println(dp[n-1][5])
}

