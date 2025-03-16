
package main

import (
    "bufio"
    "fmt"
    "os"
)

var (
    r = bufio.NewReader(os.Stdin)
    w = bufio.NewWriter(os.Stdout)
)

func main() {
    var q, h, s, d int
    fmt.Fscanf(r, "%d%d%d%d\n", &q, &h, &s, &d)
    var n int
    fmt.Fscanf(r, "%d\n", &n)
    best1L := min(q*4, h*2, s)
    best2L := min(d, best1L*2)
    if n%2 == 0 {
        fmt.Fprintf(w, "%d\n", best2L*(n/2))
    } else {
        fmt.Fprintf(w, "%d\n", best2L*(n/2)+best1L)
    }
    w.Flush()
}

func min(a, b, c int) int {
    m := a
    if b < m {
        m = b
    }
    if c < m {
        m = c
    }
    return m
}

