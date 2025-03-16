
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    var w, m, k int64
    fmt.Fscanf(in, "%d %d %d\n", &w, &m, &k)
    lo, hi := int64(0), int64(1e18)
    for hi-lo > 1 {
        md := (lo + hi) / 2
        c := sum(m+md-1) - sum(m-1)
        if c*k <= w {
            lo = md
        } else {
            hi = md
        }
    }
    fmt.Fprintf(out, "%d\n", lo)
    out.Flush()
}

func sum(k int64) int64 {
    ret, pw, len := int64(0), int64(10), int64(1)
    for {
        cur, prev := min(pw-1, k), pw/10
        ret += (cur - prev + 1) * len
        if pw-1 >= k {
            break
        }
        len++
        pw *= 10
    }
    return ret
}

func min(a, b int64) int64 {
    if a < b {
        return a
    }
    return b
}

