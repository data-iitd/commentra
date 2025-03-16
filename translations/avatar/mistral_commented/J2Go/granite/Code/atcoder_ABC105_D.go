

package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)

    var n, m int
    fmt.Fscanf(reader, "%d %d\n", &n, &m)

    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Fscanf(reader, "%d", &a[i])
    }

    dp := make(map[int]int)
    base := 0
    ans := int64(0)

    for i := 0; i < n; i++ {
        base = (base - a[i]%m + m) % m
        dp[base+a[i]%m]++
        ans += int64(dp[base])
    }

    fmt.Fprintf(writer, "%d\n", ans)
    writer.Flush()
}

// 