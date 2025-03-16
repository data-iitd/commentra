

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    n, _ := strconv.Atoi(read())
    a := readSlice()
    dp := make([]int64, n+1)
    fill(dp, -1)
    dp[n-1] = int64(a[n-1])
    for i := n - 1; i >= 0; i-- {
        dp[i] = max(dp[i+1], int64(a[i]))
    }
    for i := 0; i < n; i++ {
        if int64(a[i]) > dp[i+1] {
            fmt.Fprint(out, "0 ")
        } else {
            fmt.Fprint(out, (dp[i+1]-int64(a[i]))+1, " ")
        }
    }
    fmt.Fprintln(out)
}

func read() string {
    buf := make([]byte, 0)
    for {
        line, prefix, err := in.ReadLine()
        if err!= nil {
            panic(err)
        }
        buf = append(buf, line...)
        if prefix == false {
            break
        }
    }
    return strings.TrimSpace(string(buf))
}

func readSlice() []int {
    return readSliceInt()
}

func readSliceInt() []int {
    strs := strings.Split(read(), " ")
    slice := make([]int, 0)
    for _, str := range strs {
        num, _ := strconv.Atoi(str)
        slice = append(slice, num)
    }
    return slice
}

func max(a, b int64) int64 {
    if a > b {
        return a
    }
    return b
}

func fill(dp []int64, val int64) {
    for i := range dp {
        dp[i] = val
    }
}

func debug(a...interface{}) {
    fmt.Fprintln(os.Stderr, a...)
}

