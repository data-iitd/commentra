
package main

import (
    "fmt"
    "math"
)

func main() {
    var n int
    fmt.Scan(&n)
    beacon := make([]int, 1000001)
    dp := make([]int, 1000001)
    max := 0

    for i := 0; i < n; i++ {
        var a int
        fmt.Scan(&a)
        beacon[a] = i
    }

    if beacon[0] != 0 {
        dp[0] = 1
    }

    for i := 1; i < 1000001; i++ {
        if beacon[i] != 0 && beacon[i] < i {
            dp[i] = dp[i-beacon[i]-1] + 1
        } else if beacon[i] != 0 {
            dp[i] = 1
        } else {
            dp[i] = dp[i-1]
        }
        max = int(math.Max(float64(max), float64(dp[i])))
    }

    fmt.Println(n - max)
}

