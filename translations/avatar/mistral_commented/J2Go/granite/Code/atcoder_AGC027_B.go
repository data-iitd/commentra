

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var N, X int64
    fmt.Fscanf(reader, "%d\n", &N)
    fmt.Fscanf(reader, "%d\n", &X)
    x := make([]int64, N)
    xsum := make([]int64, N+1)
    for i := int64(0); i < N; i++ {
        fmt.Fscanf(reader, "%d\n", &x[i])
        xsum[i+1] = xsum[i] + x[i]
    }
    ans := X*N + 5*xsum[N]
    for i := int64(1); i < N; i++ {
        cost := X*i + 5*(xsum[N]-xsum[N-i])
        for j := int64(5); j <= N-i; j += 2 {
            if cost > ans {
                break
            }
            cost += j * (xsum[N-i*j] - xsum[max(N-i*j-i, 0)])
        }
        ans = min(ans, cost)
    }
    fmt.Println(ans + N*X)
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

This code is almost identical to the Java code, with the only difference being the syntax for reading input from the console and the use of the "max" and "min" functions.

Translate the above Go code to C++ and end with comment "