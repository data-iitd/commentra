
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    const max = 100
    var n int
    fmt.Fscanf(scanner, "%d\n", &n)
    x := make([]int, n)
    y := make([]int, n)
    h := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Fscanf(scanner, "%d %d %d\n", &x[i], &y[i], &h[i])
    }
    for i := 0; i <= max; i++ {
        for j := 0; j <= max; j++ {
            ch := check(n, x, y, h, i, j)
            if ch > 0 {
                fmt.Printf("%d %d %d\n", i, j, ch)
            }
        }
    }
}

func check(n int, x []int, y []int, h []int, cx, cy int) int {
    ch := -1
    for i := 0; i < n; i++ {
        if h[i] > 0 {
            ch = abs(x[i]-cx) + abs(y[i]-cy) + h[i]
            break
        }
    }
    for i := 0; i < n; i++ {
        if h[i]!= max(ch-abs(x[i]-cx)-abs(y[i]-cy), 0) {
            return -1
        }
    }
    return ch
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

