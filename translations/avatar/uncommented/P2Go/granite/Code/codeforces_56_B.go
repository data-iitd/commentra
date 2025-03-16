
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    var n int
    fmt.Fscanf(in, "%d\n", &n)
    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Fscanf(in, "%d", &a[i])
    }
    mn, mx := n+1, -1
    for i := 0; i < n; i++ {
        if i+1!= a[i] {
            mn = int(Min(int64(mn), int64(i+1)))
            mx = int(Max(int64(mx), int64(i+1)))
        }
    }
    if mx == -1 {
        fmt.Fprintf(out, "0 0\n")
    } else {
        a = append(a[:mn-1], a[mn-1:mx]...)
        a = append(a, a[mx:]...)
        if sorted(a) {
            fmt.Fprintf(out, "%d %d\n", mn, mx)
        } else {
            fmt.Fprintf(out, "0 0\n")
        }
    }
    out.Flush()
}

func Min(a, b int64) int64 {
    if a < b {
        return a
    }
    return b
}

func Max(a, b int64) int64 {
    if a > b {
        return a
    }
    return b
}

func sorted(a []int) bool {
    for i := 0; i < len(a)-1; i++ {
        if a[i] > a[i+1] {
            return false
        }
    }
    return true
}

