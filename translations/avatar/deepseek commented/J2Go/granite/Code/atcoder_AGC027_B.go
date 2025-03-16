

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var n, x int64
    fmt.Fscanf(reader, "%d %d\n", &n, &x)
    xs := make([]int64, n)
    for i := int64(0); i < n; i++ {
        fmt.Fscanf(reader, "%d", &xs[i])
    }
    xsSum := make([]int64, n+1)
    for i := int64(0); i < n; i++ {
        xsSum[i+1] = xsSum[i] + xs[i]
    }
    ans := x*n + 5*xsSum[n]
    for i := int64(1); i < n; i++ {
        cost := x*i + 5*(xsSum[n]-xsSum[n-i])
        for j := int64(5); k := n - i; k >= 0 {
            if cost > ans {
                break
            }
            cost += j * (xsSum[k] - xsSum[max(k-i, 0)])
        }
        ans = min(ans, cost)
    }
    fmt.Println(ans + n*x)
}

func max(a, b int64) int64 {
    if a > b {
        return a
    }
    return b
}

func min(a, b int64) int64 {
    if a < b {
        return a
    }
    return b
}

