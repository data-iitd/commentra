
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var n, m, x int
    fmt.Fscanf(reader, "%d %d %d\n", &n, &m, &x)
    a := make([]int, n+1)
    for i := 0; i < m; i++ {
        var temp int
        fmt.Fscanf(reader, "%d\n", &temp)
        a[temp] = 1
    }
    ansl, ansr := 0, 0
    for i := x; i <= n; i++ {
        ansr += a[i]
    }
    for i = x; i >= 0; i-- {
        ansl += a[i]
    }
    fmt.Println(min(ansl, ansr))
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

