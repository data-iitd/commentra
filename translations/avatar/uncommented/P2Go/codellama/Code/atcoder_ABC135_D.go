package main
import (
    "fmt"
    "math"
    "strings"
)
func main() {
    var n int
    fmt.Scan(&n)
    if n == 1 {
        var s string
        fmt.Scan(&s)
        if s == "5" || s == "?" {
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
            var s string
            fmt.Scan(&s)
            if s != "?" {
                dp[i][int(s[0])-'0']++
            } else {
                for j := 0; j < 10; j++ {
                    dp[i][j]++
                }
            }
        } else {
            var s string
            fmt.Scan(&s)
            if s != "?" {
                for k := 0; k < 13; k++ {
                    dp[i][(k*10+int(s[0])-'0')%13] += dp[i-1][k]
                }
            } else {
                for j := 0; j < 10; j++ {
                    for k := 0; k < 13; k++ {
                        dp[i][(k*10+j)%13] += dp[i-1][k]
                    }
                }
            }
            for k := 0; k < 13; k++ {
                dp[i][k] %= 1000000007
            }
        }
    }
    fmt.Println(dp[n-1][5])
}



Translate the above Go code to C++ and end with comment "